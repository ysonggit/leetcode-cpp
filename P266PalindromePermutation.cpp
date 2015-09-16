class Solution {
public:
    bool canPermutePalindrome(string s) {
        int n = s.length();
        vector<int> freq(256, 0);
        for(char c : s){
            freq[(int) c]++;
        }
        int count_of_odd_occur =0;
        for(int num : freq){
            if(num%2==1) count_of_odd_occur++;
        }
        return count_of_odd_occur > 1 ? false : true;
    }
};
