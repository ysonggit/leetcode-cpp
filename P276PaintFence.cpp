class Solution {
public:
    int numWays(int n, int k) {
        if(n==0||k==0) return 0;
        if(n<3) return (int) pow(k,n);
        // D[i] : the number of ways painting first i fences
        // mistake : use one D is not enough
        // dp1[i] means the number of solutions when the color of last two fences (whose indexes are i-1,i-2) are same. 
        // dp2[i] means the number of solutions when the color of last two fences are different.
        int D1 = k;
        int D2 = k * (k-1);
        for(int i=2; i<n; i++){
            int num_ways_diff_from_last = D1 * (k-1);
            int num_ways_same_to_last = D2 * (k-1);
            D1 = D2;
            D2 = num_ways_same_to_last+num_ways_diff_from_last;
        }
        return D1+D2;
    }
};
