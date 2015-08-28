class Solution {
public:
    void reverseInplace(string &s, int front, int back){
        while(front<back){
            swap(s[front], s[back]);
            front++;
            back--;
        }
    }
    void reverseWords(string &s) {
        int n = s.length();
        if(n==0) return;
        // reverse entire str
        reverseInplace(s, 0, n-1);
        // reverse each word
        int start = 0, i = 0;
        while(i<n){
            if(s[i]==' ' || i==n-1){
                int end = (i==n-1) ? i : i-1;
                reverseInplace(s, start, end);
                start = i+1;
            }
            i++;
        }
    }
};
