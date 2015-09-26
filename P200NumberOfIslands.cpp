class Solution {
public:
    // BFS
    struct Pos{
        int x, y;
        Pos(int i, int j): x(i), y(j){}
    };
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int count = 0;
        if(m==0) return count;
        int n = grid[0].size();
        queue<Pos> Q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='0') continue;
                // BFS one island while overwrite 1's to 0's
                grid[i][j]='0';
                Q.push(Pos(i, j));
                while(!Q.empty()){
                    int num = Q.size();
                    for(int k=0; k<num; k++){
                        auto cur = Q.front();
                        Q.pop();
                        for(int t=0; t<4; t++){
                            Pos nb(cur.x+dx[t], cur.y+dy[t]);
                            if(nb.x<0||nb.y<0||nb.x>=m||nb.y>=n) continue;
                            if(grid[nb.x][nb.y]=='0') continue;
                            grid[nb.x][nb.y] = '0';
                            Q.push(nb);
                        }
                    }
                }
                count++;
            }
        }
        return count;
    }
};
