class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n<=0) return vector<vector<int> >{};
        vector<vector<int> > mat(n, vector<int>(n));
        int top_row=0, bottom_row = n-1, left_col=0, right_col=n-1;
        int i = 1;
        while(true){
            for(int j=left_col; j<=right_col; j++){
                mat[top_row][j] = i++;
            }
            top_row++;
            if(top_row>bottom_row) break;
            for(int j=top_row; j<=bottom_row; j++){
                mat[j][right_col] = i++;
            }
            right_col--;
            if(right_col < left_col) break;
            for(int j=right_col; j>=left_col; j--){
                mat[bottom_row][j] = i++;
            }
            bottom_row--;
            if(bottom_row < top_row) break;
            for(int j=bottom_row; j>=top_row; j--){
                mat[j][left_col] = i++;
            }
            left_col++;
            if(left_col>right_col) break;
        }
        return mat;
    }
};
