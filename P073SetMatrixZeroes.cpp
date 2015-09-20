class Solution {
public:
     void zeroCol(vector<vector<int>> &matrix, int col){
        for(int i=0; i<matrix.size(); i++){
            matrix[i][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0) return;
        int n = matrix[0].size();
        bool zero_row0 = false, zero_col0=false;
        for(int i=0; i<m; i++){
            if(matrix[i][0]==0) zero_col0 = true;
        }
        for(int j=0; j<n; j++){
            if(matrix[0][j]==0) zero_row0 = true;
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1; i<m; i++){ // zero rows
            if(matrix[i][0]==0) fill_n(matrix[i].begin(), n, 0);
        }
        for(int j=1; j<n; j++){
            if(matrix[0][j]==0) zeroCol(matrix, j);
        }
        if(zero_row0) fill_n(matrix[0].begin(),n, 0);
        if(zero_col0) zeroCol(matrix, 0);
    }
};
