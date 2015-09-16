class Solution {
public:
    void dfs(vector<vector<int> >& res, vector<int> sol, int n, int start){
        if(n==1){
            if(sol.size()==1) return; // pass by n itself
            sort(sol.begin(), sol.end());
            res.push_back(sol);
            return;
        }
        for(int factor=start; factor<=n; factor++){
            if(n%factor==0){
                sol.push_back(factor);
                dfs(res, sol, n/factor, factor);
                sol.pop_back();
            }
        }
    }
    vector<vector<int>> getFactors(int n) {
        vector<vector<int> > res;
        if(n<4) return res;
        vector<int> sol;
        dfs(res, sol, n, 2);
        return res;
    }
};
