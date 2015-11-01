class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls =0, cows = 0;
        int count[10]={0};
        for(int i=0; i<guess.length(); i++){
            int s = secret[i]-'0', g = guess[i]-'0';
            if(s==g){
                bulls++;
            }else{
                if(count[s]>0) cows++;
                if(count[g]<0) cows++;
                count[s]--;
                count[g]++;
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
