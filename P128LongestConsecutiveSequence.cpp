class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i : nums){
            s.insert(i);
        }
        int max_len = 1;
        for(int i : s){
            int left = i-1, right = i+1;
            int len = 1;
            while(s.find(left)!= s.end()){
                len++;
                left--;
                s.erase(left+1);
            }
            while(s.find(right)!=s.end()){
                len++;
                right++;
                s.erase(right-1);
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
