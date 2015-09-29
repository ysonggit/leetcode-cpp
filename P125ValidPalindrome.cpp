class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if(n==0) return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int front =0, back=n-1;
        while(front<back){
            while(front<back && !isalnum(s[front])) front++;
            while(front<back && !isalnum(s[back])) back--;
            if(s[front]!=s[back]) return false;
            front++;
            back--;
        }
        return true;
    }
};
