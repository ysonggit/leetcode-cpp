class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==1) return 1;
        vector<int> super_ugly(n,1);
        int k = primes.size();
        vector<int> L(k, 0);
        for(int i=1; i<n; i++){
            int num = INT_MAX;
            for(int j=0; j<k; j++){
                num = min(num, super_ugly[L[j]]*primes[j]);    
            }
            // must finish computing num
            for(int j=0; j<k; j++){           
                if(num%primes[j]==0) L[j]++;
            }
            super_ugly[i] = num;
        }
        return super_ugly[n-1];
    }
};
