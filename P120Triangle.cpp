class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==0) return 0;
        vector<int> D(n,0);
        vector<int> pre = D;
        D[0] = triangle[0][0];
        for(int i=1; i<n; i++){
            // from row 1 to row n-1
            pre = D;
            for(int j=0; j<=i; j++){
                // the j-th element in row i
                int cur = triangle[i][j];
                if(j>0 && j<i) D[j] = min(pre[j-1], pre[j]) + cur;
                else if(j==0) D[j] = cur + pre[j];
                else D[j] = cur + pre[j-1];
            }
        }
        return *min_element(D.begin(), D.end());
    }
};
