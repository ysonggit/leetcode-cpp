class Solution {
public:
    // assume no overflow
    int titleToNumber(string s) {
        int n= s.length();
        if(n==0) return 0;
        unsigned int rightmost = (unsigned int) (s[n-1] - 'A'+1);
        return titleToNumber(s.substr(0, n-1)) * 26 + rightmost;
    }
};
