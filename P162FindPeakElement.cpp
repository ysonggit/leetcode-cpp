class Solution {
public:
    int binarySearch(vector<int> & nums, int low, int high){
        if(low>high) return -1;
        if(high-low<=1) return nums[low] > nums[high] ? low : high;
        int mid = low + (high-low)/2;
        int left = mid-1 < 0 ? INT_MIN : nums[mid-1];
        int right = mid+1>=nums.size() ? INT_MIN : nums[mid+1];
        if(nums[mid] > left && nums[mid] > right) return mid;
        if(nums[mid] < right) return binarySearch(nums, mid+1, high);
        return binarySearch(nums, low, mid-1);
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return binarySearch(nums, 0, n-1);
    }
};
