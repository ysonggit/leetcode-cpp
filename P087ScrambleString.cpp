class Solution {
public:
    /**
     * Divide and Conquer
     * s1 = s11 + s12
     * s2 = s21 + s22     tsgo : ts + go
     *    = s21_ + s22_   tsgo : go (+) ts 
     * isScramble(s1, s2) is true if
     * isScramble(s11, s21) && isScramble(s12, s22)
     * OR
     * isScramble(s11, s21_) && isScramble(s12, s22_)
     */ 
    bool isScramble(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n==0) return m==0;
        if(n!=m) return false;
        if(s1 == s2) return true;
        string s1_sort = s1, s2_sort = s2;
        sort(s1_sort.begin(), s1_sort.end());
        sort(s2_sort.begin(), s2_sort.end());
        if(s1_sort != s2_sort) return false;
        for(int len = 1; len<n; len++){
            string s11 = s1.substr(0, len);
            string s21 = s2.substr(0, len);
            string s12 = s1.substr(len, n);
            string s22 = s2.substr(len, n);
            if(isScramble(s11, s21) && isScramble(s12, s22)) return true;
            string s21_ = s2.substr(n-len, len);
            string s22_ = s2.substr(0, n-len);
            if(isScramble(s11, s21_) && isScramble(s12, s22_)) return true;
        }
        return false;
    }
};
