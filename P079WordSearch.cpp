class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, 
            int cur_idx, int i, int j, bool ** visited){
        int m = board.size(), n = board[0].size();
        if(cur_idx>=word.size()) return true;
        if(i<0 || i>=m || j<0 || j>=n || visited[i][j]) return false;
        if(word[cur_idx]!=board[i][j]) return false;
        visited[i][j] = true;
        bool found = dfs(board, word, cur_idx+1, i+1, j, visited) ||
                    dfs(board, word,  cur_idx+1, i, j+1, visited) ||
                    dfs(board, word,  cur_idx+1, i-1, j, visited) ||
                    dfs(board, word,  cur_idx+1, i, j-1, visited);
        visited[i][j] = false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if(m==0) return word=="";
        int n = board[0].size();
        bool ** visited = new bool *[m]; // use 2D vector => TLE
        for(int i=0; i<m; i++){
            visited[i] = new bool[n];
            for(int j=0; j<n; j++){
                visited[i][j] = false;
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(word[0]==board[i][j] && dfs(board, word, 0, i, j, visited)) return true;
            }
        }
        for(int i=0; i<m; i++){
            delete [] visited[i];
        }
        delete [] visited;
        return false;
    }
};
