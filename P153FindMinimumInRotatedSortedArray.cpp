class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high){
        if(low==high) return nums[low];
        // tricky: [1 2] [2 1]
        if(low+1==high) return min(nums[low], nums[high]);
        int mid = low + (high-low)/2;
        if(nums[mid] < nums[high]) return binarySearch(nums, low, mid);
        return binarySearch(nums, mid+1, high);
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        return binarySearch(nums, 0, n-1);
    }
};
