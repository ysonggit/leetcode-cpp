class Solution {
public:
    // O(log(m+n)) method
    double findKthMin(vector<int>& A, vector<int>& B, int k){
        int m = A.size(), n= B.size();
        if(m>n) return findKthMin(B, A, k);
        if(m==0) return B[k-1];
        if(k==1) return min(A[0], B[0]);
        int i = min(k/2, m);
        int j = k-i;
        int a_i = A[i-1], b_j = B[j-1];
        if(a_i < b_j) {
            vector<int> A_trunc;
            for(int idx= i; idx<m; idx++) A_trunc.push_back(A[idx]);
            return findKthMin(A_trunc, B, k-i);
        }
        if(a_i > b_j){
            vector<int> B_trunc;
            for(int idx=j;  idx<n; idx++) B_trunc.push_back(B[idx]);
            return findKthMin(A, B_trunc, k-j);
        } 
        return a_i;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m+n;
        if(total%2==1){
            return findKthMin(nums1, nums2, total/2+1);
        }
        return (findKthMin(nums1, nums2, total/2) + findKthMin(nums1, nums2, total/2+1))/2.0;
    }
};
