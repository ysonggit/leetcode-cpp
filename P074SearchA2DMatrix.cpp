class Solution {
public:
    // convert to row major order 1d array 
    // binary search O(log(mn))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0) return false;
        int n = matrix[0].size();
        int low = 0, high = m*n;
        while(low<high){
            int mid=low+(high-low)/2;
            int i = mid/n;
            int j = mid - i * n;
            if(target == matrix[i][j]){
                return true;
            }else if(target < matrix[i][j]){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
};
