class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int m = A.size();
        if(m==0) return res;
        int n = A[0].size(), k = B[0].size();
        res.resize(m, vector<int>(k, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                for(int l=0; l<k; l++){
                    if(A[i][j]!=0) res[i][l] += A[i][j] * B[j][l];
                }
            }
        }
        return res;
    }
};
