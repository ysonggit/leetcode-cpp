class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        if(n<3) return n;
        int count [256]={0};
        int startpos = 0, i = 0;
        int max_len = 0, num_distincts = 0;
        while(i<n){
            unsigned int idx = (unsigned int) s[i];
            if(count[idx]==0) num_distincts++;
            count[idx]++;
            while(num_distincts>2){
                // move startpos while decrease count[c], c is the char passed by
                count[(unsigned int) s[startpos] ]--; // mistake: count[s[startpos]] not count[startpos]
                if(count[(unsigned int) s[startpos] ]==0) num_distincts--;
                startpos++;
            }
            max_len = max(max_len, i-startpos+1);
            i++;
        }
        return max_len;
    }
};
