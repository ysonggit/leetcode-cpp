class Solution {
public:
    void dfs(vector<vector<int> > & res, int n, int k, vector<int> sol, int cur){
        if(sol.size()==k){
            res.push_back(sol);
            return;
        }
        //if(cur>n) return;
        for(int i = cur; i<=n; i++){
            sol.push_back(i);
            dfs(res, n, k, sol, i+1);
            sol.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res; 
        if(k>n || k<=0 ||n<=0) return res;
        vector<int> sol;
        dfs(res, n, k, sol, 1);
        return res;
    }
};
