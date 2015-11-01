class Solution1 {
public:
    // naive solution
    string getHint(string secret, string guess) {
        int bulls =0, cows = 0;
        string s, g;
        for(int i=0; i<guess.length(); i++){
            if(guess[i]==secret[i]) bulls++;
            else{
                s += secret[i];
                g += guess[i];
            }
        }
        unordered_map<char, int> count_s, count_g;
        for(int i=0; i<s.length(); i++){
            count_s[s[i]]++;
            count_g[g[i]]++;
        }
        for(auto g_entry : count_g){
            char gc = g_entry.first;
            if(count_s[gc]>0) {
                cows += min(count_s[gc], count_g[gc]); // trick
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};

class Solution2 {
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
