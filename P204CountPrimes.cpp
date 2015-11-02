class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        bool A[n];
        fill_n(A, n, true);
        for(int i=2; i<n; i++){
            if(!A[i]) continue;
            for(int j=i*2; j<n; j+=i){
                A[j] = false;
            }
        }
        int count = 0;
        for(int i=2; i<n; i++){
            if(A[i]) count++;
        }
        return count;
    }
};
