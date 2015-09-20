class Solution {
public:
    int climbStairs(int n) {
        if(n<0) return 0;
        vector<int> D(n+1, 1);
        for(int i=2; i<=n; i++){
            D[i] = D[i-1] + D[i-2];
        }
        return D[n];
    }
};
