class Solution {
public:
    // double pointers 
    int lengthOfLongestSubstring(string s) {
       // char_pos[i] = j means the i-th char appears at pos j
       vector<int> char_pos(256, -1);
       int start = 0, n= s.length();
       int max_len = 0;
       for(int i = 0; i < n; i++){
           char cur = s[i];
           if(char_pos[cur]>= start){
               // dup found, reset start
               start = char_pos[cur] + 1;
           }
           char_pos[cur] = i;
           max_len = max(max_len, i-start+1);
       }
       return max_len;
    }
};
