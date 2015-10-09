class Solution {
public:
    string convertToTitle(int n) {
        if(n<=0) return "";
        int offset = (n-1) % 26;
        return convertToTitle((n-1)/26)+string(1, (char)(offset+'A'));
    }
};
