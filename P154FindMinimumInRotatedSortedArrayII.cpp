class Solution {
public:
    int binarySearch(vector<int> & nums, int low, int high){
        if(low==high) return nums[low];
        if(low+1==high) return min(nums[low], nums[high]);
        int mid = low + (high-low)/2;
        if(nums[mid]>nums[high]){
            return binarySearch(nums, mid+1, high);
        }else if(nums[mid]<nums[high]){
            return binarySearch(nums, low, mid);
        }
        return binarySearch(nums, low, high-1);
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        return binarySearch(nums, 0, n-1);
    }
};
