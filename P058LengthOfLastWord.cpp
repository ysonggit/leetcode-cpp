class Solution {
public:
    int lengthOfLastWord(string s) {
       int n=s.length(), count = 0;
       int back=n-1;
       while(back>=0 && s[back]==' ') back--;
       while(back>=0 && s[back]!=' '){
           count++;
           back--;
       }
       return count;
    }
};
