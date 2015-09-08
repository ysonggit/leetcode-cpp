class Solution {
public:
    /**
     * ideally, A[i] = i+1 swap A[A[i]-1] with A[i]
     * maintain: A[A[i] ]= i by keep on swapping numbers
     *     0 1  2 3
     *    [3 4 -1 1]
     * i=0 A[i]=3 A[A[i]-1] = -1
     *    [-1 4 3 1]
     * i=1 A[i]=4 A[A[i]-1] = 1
     *    [-1 1 3 4]
     * i=2 A[i]=3 A[A[i]-1] = 4
     *    return i+1 such that A[i] != i+1
     */ 
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            // mistake 1: must check 0<nums[i]<n both sides
            // mistake 2: compare A[A[i]-1] with A[i]! not simply i+1
            while(nums[i] > 0 && nums[i]<n && nums[nums[i]-1] !=nums[i]){
                int cur = nums[i];
                swap(nums[cur-1], nums[i]);
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
