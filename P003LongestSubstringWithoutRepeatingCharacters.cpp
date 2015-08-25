class Solution {
public:
    // double pointers 
    int lengthOfLongestSubstring(string s) {
       int n = s.length();
       if(n<2) return n;
       // char_count[i] = j means the i-th char appears j times
       vector<int> char_count(256, 0);
       int front = 0, back=0;
       int max_len = 1;
       while(back<n){
           unsigned int cur_pos_idx = (unsigned int) s[back];
           char_count[cur_pos_idx]++; // mistake : idx not equal to back!! idx('a') = 97
           while(char_count[cur_pos_idx]>1){
                // move front
                while(front<back){
                    unsigned int pre_pos_idx = (unsigned int) s[front]; 
                    char_count[pre_pos_idx]--;
                    front++;
                    if(char_count[cur_pos_idx]==1) break; // important!
                }    
           }
           max_len = max(max_len, back-front+1);
           back++;
       }
       return max_len;
    }
};
