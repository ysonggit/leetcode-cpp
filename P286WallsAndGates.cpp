class Solution {
public:
    struct Pos{
        int x, y;
        Pos(int i, int j): x(i), y(j){}
    };
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    // search all gates position, put into queue as level 0 nodes
    // for each gate, do BFS
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int m = rooms.size();
        if(m==0) return;
        int n = rooms[0].size();
        bool visited[m][n];
        queue<Pos> Q;
        for(int i=0; i<m; i++){
            fill_n(visited[i], n, false);
            for(int j=0; j<n; j++){
                if(rooms[i][j]==0){
                    Q.push(Pos(i, j));
                    visited[i][j] = true;
                }
            }
        }
        int level = 1;
        while(!Q.empty()){
            int num_cur_level = Q.size();
            for(int i=0; i<num_cur_level; i++){
                //visit neighbors
                auto cur = Q.front();
                Q.pop();
                for(int j=0; j<4; j++){
                    Pos nb(cur.x + dx[j], cur.y + dy[j]);
                    if(nb.x >=m || nb.x <0 || nb.y>=n || nb.y<0) continue;
                    if(rooms[nb.x][nb.y]==-1 || visited[nb.x][nb.y]) continue;
                    visited[nb.x][nb.y] = true;
                    Q.push(nb);
                    rooms[nb.x][nb.y] = level;
                }
            }
            level++;
        }
    }
};
