class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int low, int high){
        if(low>high) return low;//[1] 0  ; [1] 2   // mistake > not >=
        int mid = low+(high-low)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) {
            return binarySearch(nums, target, mid+1, high);
        }
        return binarySearch(nums, target, low, mid-1);
    }
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        return binarySearch(nums, target, 0, n-1); // mistake : n-1 not n
    }
};
