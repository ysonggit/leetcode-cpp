class Solution {
public:
    /**
     * D[i]: the least # of perfect squares sum to i
     * D[i] = 1 if i is a perfect square
     *       min(D[k] + 1) if i-k is a perfect square
     * 
     */ 
    //unordered_map<int, int> D; // TLE
    
    bool isPerfectSquare(int n){
        if(n<=0) return false;
        int m = (int)sqrt(n);
        return (m*m==n) ? true : false;
    }
    
    int helper(int n, vector<int> & D){
        if(D[n]<INT_MAX) return D[n];
        if(isPerfectSquare(n)){
            D[n] = 1;
            return 1;
        }
        int min_perfect_sq = n; // worst case 1+1+..
        for(int k=1; (k*k)<=n; k++){ 
            min_perfect_sq = min(min_perfect_sq, helper(n-k*k, D)+1);
        }
        D[n] = min_perfect_sq;
        return min_perfect_sq;
    }
    
    int numSquares(int n) {
        if(n<=0) return 0;
        vector<int> D(n+1, INT_MAX);
        helper(n, D);
        return D[n];
    }
};
