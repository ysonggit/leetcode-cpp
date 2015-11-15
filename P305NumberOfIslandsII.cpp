class Solution {
public:
    vector<int> roots; // roots[i] = j means the parent of A[i] is A[j]
    int find(int idx){
        if(idx==roots[idx]) return idx;
        roots[idx] = find(roots[idx]);
        return roots[idx];
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if(m==0) return res;
        roots.resize(m*n);
        vector<vector<int> > filled(m, vector<int>(n, 0));
        int num_islands = 0;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        for(auto p : positions){
            int i = p.first, j = p.second;
            filled[i][j] = 1;
            // important! initial root
            int cur_idx = i* n+ j; // use row-major index 
            roots[cur_idx] = cur_idx;
            num_islands++;
            for(int k=0; k<4; k++){
                int nb_i = i+dx[k], nb_j=j+dy[k];
                if(nb_i<0||nb_j<0||nb_i>=m||nb_j>=n) continue;
                if(filled[nb_i][nb_j]==0) continue;
                int nb_idx = nb_i * n + nb_j;
                int nb_root = find(nb_idx);
                int cur_root = find(cur_idx);
                if(nb_root != cur_root) num_islands--;
                roots[nb_root] = cur_root;
            }
            res.push_back(num_islands);
        }
        return res;
    }
};
