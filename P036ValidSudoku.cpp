class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> rows[9], cols[9], blocks[9];
        for(int i = 0; i<9; i++){
            for(int j=0; j<9; j++){
                char c = board[i][j];
                if(c=='.') continue;
                // check row rows[i][c] = k means i-th row, c occurs k times
                rows[i][c]++;
                if(rows[i][c]>1) return false;
                // cehck col cols[j][c] = k means j-th col, c occurs k times
                cols[j][c]++;
                if(cols[j][c]>1) return false;
                // check block blocks[m][c] = k means m-th block, c occurs k times
                int m = i/3*3+j/3;
                blocks[m][c]++;
                if(blocks[m][c]>1) return false;
            }
        }
        return true;
    }
};
