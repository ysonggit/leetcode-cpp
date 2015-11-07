class Solution {
public:
    struct Pos{
        int x, y;
        Pos(int i, int j) : x(i), y(j){}
    };
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        if(m==0) return 0;
        int n = image[0].size();
        int max_i = x, min_i = x, max_j = y, min_j = y;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[x][y] = 1;
        queue<Pos> Q;
        Q.push(Pos(x,y));
        while(!Q.empty()){
            int num = Q.size();
            for(int z=0; z<num; z++){
                Pos cur = Q.front();
                Q.pop();
                for(int k=0; k<4; k++){
                    Pos nb = Pos(cur.x+dx[k], cur.y+dy[k]);
                    if(nb.x<0||nb.y<0||nb.x==m||nb.y==n) continue;
                    if(visited[nb.x][nb.y]==1) continue;
                    if(image[nb.x][nb.y]=='1'){
                        visited[nb.x][nb.y] = 1;
                        Q.push(nb);
                        max_i = max(max_i, nb.x);
                        max_j = max(max_j, nb.y);
                        min_i = min(min_i, nb.x);
                        min_j = min(min_j, nb.y);
                    }
                }
            }
        }
        return (max_i-min_i+1)*(max_j-min_j+1); // assume no overflow
    }
};
