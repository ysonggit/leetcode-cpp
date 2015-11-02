class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shifted = 0;
        while(m!=n){
            m>>=1;
            n>>=1;
            shifted++;
        }
        return m<<shifted; // not 1<<shifted
    }
};
