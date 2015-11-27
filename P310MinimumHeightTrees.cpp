class Solution {
public:
    // Brute-force TLE 
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<n; i++) graph[i] = vector<int>{};
        for(auto e : edges){
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }
        int min_depth = n+1;
        unordered_map<int, int> root_depth;
        for(int i=0; i<n; i++){
            queue<int> Q;
            bool visited[n];
            fill_n(visited, n, false);
            visited[i] = true;
            Q.push(i);
            int depth = 0;
            while(!Q.empty()){
                int num = Q.size();
                for(int k=0; k<num; k++){
                    int m = Q.front();
                    Q.pop();
                    for(auto j : graph[m]){
                        if(visited[j]) continue;
                        visited[j] = true;
                        Q.push(j);
                    }
                }
                depth++;
            }
            root_depth[i] = depth;
            min_depth = min(depth, min_depth);
        }
        for(auto entry : root_depth){
            if(entry.second==min_depth) res.push_back(entry.first);
        }
        return res;
    }
};
