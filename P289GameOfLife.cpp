class Solution {
public:
    /**
     * use two bits to denote the transition
     * the right is the current state, left is the next state
     * 00 
     * 01
     * 10 
     * 11 
     */ 
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();
        int neighbors[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count =0; 
                for(int k=0; k<8; k++){
                    int x = i+neighbors[k][0], y = j+neighbors[k][1];
                    if(x<0||y<0||x>=m||y>=n) continue;
                    if(board[x][y] & 1==1) { // live
                        count++;
                    }
                }
                if(board[i][j] ==0){
                    if(count==3) board[i][j] = 2; // 10 from die to live
                    
                }else{
                    if(count<2 || count>3) {
                        board[i][j]=1; // 01 from live to die 
                    }else{
                        board[i][j]=3;
                    }
                }
            }   
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                board[i][j] >>= 1;
            }
        }
     }
};
