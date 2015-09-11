class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high){
        if(low==high) return nums[low];
        // tricky: [1 2] [2 1]
        if(low+1==high) return min(nums[low], nums[high]);
        int mid = low + (high-low)/2;
        int left = mid-1; // guaranteed >= 0
        int right = mid+1; // guaranteed <n
        if(nums[mid]< nums[left] && nums[mid] < nums[right]){
            return nums[mid];
        }
        int left_min = binarySearch(nums, low, mid-1);
        int right_min = binarySearch(nums, mid+1, high);
        return min(left_min, right_min);
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        return binarySearch(nums, 0, n-1);
    }
};
