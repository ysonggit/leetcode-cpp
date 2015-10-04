class Solution {
public:
    int offset[3] = {1,-1,0};
    int liveNeighbors(bool ** states, int i, int j, int m, int n){
        int count = 0;
        for(int x=-1; x<=1; x++){
            for(int y=-1; y<=1; y++){
                if(x==y && x==0) continue;
                int nb_x = i+x, nb_y = j+y;
                if(nb_x < 0 || nb_x ==m || nb_y<0 || nb_y==n) continue;
                if(states[nb_x][nb_y]) count++;
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();
        bool ** states = new bool*[m];
        for(int i=0; i<m; i++){
            states[i] = new bool[n];
            for(int j=0; j<n; j++){
                states[i][j] = board[i][j]>0 ? true : false;
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int lives = liveNeighbors(states, i, j, m, n);
                if(states[i][j]==1){
                    if(lives<2 || lives >3) board[i][j] = 0;
                }else{
                    if(lives==3) {
                        board[i][j]= 1;
                    }
                }
            }   
        }
        for(int i=0; i<m; i++){
            delete [] states[i];
        }
        delete [] states;
     }
};
