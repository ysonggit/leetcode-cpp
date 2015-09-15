class Solution {
public:
    bool isValid(vector<vector<char> > & board, int i, int j){
        for(int k=0; k<9; k++) {
            if(board[i][k]==board[i][j] && k != j) return false; // dup number on same row
            if(board[k][j]==board[i][j] && k != i) return false; // dup number on same col
        }
        for(int sub_row_idx = i/3*3; sub_row_idx < i/3*3+3; sub_row_idx++){
            for(int sub_col_idx = j/3*3; sub_col_idx < j/3*3+3; sub_col_idx++){
                if(i!= sub_row_idx && j!= sub_col_idx 
                    && board[i][j]==board[sub_row_idx][sub_col_idx]) return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<char>>& board, int i, int j){
        if(j==9) return dfs(board, i+1, 0); // iterate next row
        if(i==9) return true;
        if(board[i][j]=='.'){
            // try each digit in board[i][j]
            for(char k='1'; k<='9'; k++){
                // reset 
                board[i][j] = k;
                if(isValid(board, i, j)) {
                    if(dfs(board, i, j+1)) return true;
                }
                // recover 
                board[i][j] = '.';
            }
        }else{
            return dfs(board, i, j+1);
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size()==0) return;
        dfs(board, 0, 0);
    }
};
