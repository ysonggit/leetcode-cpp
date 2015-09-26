class Solution {
public:
    struct Pos{
        int x, y;
        Pos(int i, int j): x(i), y(j){}
    };
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    // treat 0's on the boarder as the first level nodes
    void solve(vector<vector<char>>& board) {
        const int m = board.size();
        if(m==0) return;
        const int n= board[0].size();
        bool visited[m][n];
        queue<Pos> Q;
        for(int i=0; i<m; i++){
            fill_n(visited[i], n, false);
             for(int j=0; j<n; j++){
                if(i==0||j==0|| i==m-1||j==n-1){
                    if(board[i][j]=='O'){
                        visited[i][j] = true;
                        Q.push(Pos(i, j));
                        board[i][j]='Y';
                    }
                }
            }
        }
        while(!Q.empty()){
            int num_cur_level = Q.size();
            for(int i=0; i<num_cur_level; i++){
                auto cur = Q.front();
                Q.pop();
                for(int k=0; k<4; k++){
                    Pos nb(cur.x+dx[k], cur.y+dy[k]);
                    if(nb.x<0 || nb.x>=m || nb.y<0 || nb.y>=n) continue;
                    if(visited[nb.x][nb.y] || board[nb.x][nb.y]=='X') continue;
                    visited[nb.x][nb.y] = true;
                    board[nb.x][nb.y] = 'Y';
                    Q.push(nb);
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='Y') board[i][j]='O';
            }
        }
    }
};
