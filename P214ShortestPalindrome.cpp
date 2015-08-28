class Solution {
public:
    // 1 kmp prefix table
    // 2 http://www.jiuzhang.com/solutions/shortest-palindrome/ 
    /** 
          aacecaaa
          01234567
          1. find the first pos j that left the string non-palindrome (j=7)
          2. get suffix s.substr(j)
          3. get prefix = reverse of the suffix
          4. recursion: mid = shortestPalindrome(s.substr(0,j))
          5. return prefix+mid+suffix
          step 1 and step 4 are essential
          abbb
    */
    string shortestPalindrome(string s) {
        int n = s.length();
        if(n<2) return s;
        int j = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i]==s[j]){
                j++;
            }
        }
        if(j==n) {
            // s is already a palindrome, so the shortest one is itself
            return s;
        }
        string suffix = s.substr(j);
        string prefix = suffix;
        reverse(prefix.begin(), prefix.end());
        string mid = shortestPalindrome(s.substr(0, j));
        return prefix+mid+suffix;
    }
};
