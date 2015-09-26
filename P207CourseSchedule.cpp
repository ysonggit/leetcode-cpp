class Solution {
public:
    // numcourses are 0, 1, ... 
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(prerequisites.size()==0) return true;
        // construct graph: incomings[i] = j: course i has j in-edges/pre-courses 
        vector<int> incomings(numCourses, 0);
        // adjacencies[i]={j,k,..} node i has neighbors j, k, ..
        unordered_map<int, vector<int>> adjacencies;
        for(auto p: prerequisites){
            int cur = p.first;
            int pre = p.second;
            incomings[cur]++;
            if(adjacencies.find(pre)== adjacencies.end()){
                adjacencies[pre] = vector<int>{};
            }
            adjacencies[pre].push_back(cur); 
        }
        queue<int> no_inedges;
        for(int i=0; i<incomings.size(); i++){
            if(incomings[i]==0) no_inedges.push(i);
        }
        while(!no_inedges.empty()){
            int pre = no_inedges.front();
            no_inedges.pop();
            for(int nb_id : adjacencies[pre]){
                // remove edge from cur_id to this adjacency
                incomings[nb_id]--;
                if(incomings[nb_id]==0){
                    no_inedges.push(nb_id);
                }
            }
        }
        for(int i : incomings){
            if(i>0) return false;
        }
        return true;
    }
};
