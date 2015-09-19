class Solution {
public:
    // queens[i] =j there is a queen in row i and col j
    // cols_occupied[i] = true means the a queen is already in col i
    void dfs(vector<vector<string>> & res, vector<int> queens, 
            vector<int> cols_occupied, int cur_row){
        int n = queens.size();
        if(cur_row >= n){
            // generate solution from queens
            vector<string> sol = generateSolution(queens);
            res.push_back(sol);
            return;
        }
        for(int cur_col=0; cur_col<n; cur_col++){
            if(isValid(queens, cols_occupied, cur_row, cur_col)){
                cols_occupied[cur_col] = 1;
                queens[cur_row] = cur_col;
                dfs(res, queens, cols_occupied, cur_row+1);
                cols_occupied[cur_col] = 0;
                queens[cur_row] = -1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if(n==0) return res;
        vector<int> queens(n, -1);
        vector<int> cols_occupied(n, 0);
        dfs(res, queens, cols_occupied, 0);
        return res;
    }
    bool isValid(const vector<int> & queens, 
                const vector<int> & cols_occupied,
                int i, int j){
        // check col collision
        if(cols_occupied[j]>0) return false;
        // check diagonal collision
        for(int row = 0; row<i; row++){
            int col= queens[row];
            if(col >=0 && i-row == abs(j-col)) return false;
        }
        return true;
    }
    vector<string> generateSolution(const vector<int> & queens){
        string empty_row;
        int n = queens.size();
        for(int i=0; i<n; i++) empty_row.push_back('.');
        vector<string> board(n, empty_row);
        for(int row = 0; row<queens.size(); row++){
            int col = queens[row];
            board[row][col] = 'Q';
        }
        return board;
    }
};
