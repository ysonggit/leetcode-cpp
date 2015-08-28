class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        if(rows==0) return res;
        int cols = matrix[0].size();
        int top_row = 0, bottom_row = rows-1, left_col = 0, right_col=cols-1;
        while(true){
            for(int i=left_col; i<= right_col; i++){
                res.push_back(matrix[top_row][i]);
            }
            top_row++;
            if(top_row>bottom_row) break;  // mistake: top_row>= rows, think of it carefully
            for(int j=top_row; j<=bottom_row; j++){
               res.push_back(matrix[j][right_col]);
            }
            right_col--;
            if(right_col<left_col) break;
            for(int i=right_col; i>=left_col; i--){
                res.push_back(matrix[bottom_row][i]);
            }
            bottom_row--;
            if(bottom_row<top_row) break;
            for(int j= bottom_row; j>=top_row; j--){
                res.push_back(matrix[j][left_col]);
            }
            left_col++;
            if(left_col>right_col) break; 
        }
        return res;
    }
};
