class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        vector<int> ugly(n,1);
        int l1=0, l2=0, l3=0;
        for(int i=1; i<n; i++){
            int num = min({ugly[l1]*2, ugly[l2]*3, ugly[l3]*5});
            if(num%2==0) l1++;
            if(num%3==0) l2++;
            if(num%5==0) l3++;
            ugly[i] = num;
        }
        return ugly[n-1];
    }
};
