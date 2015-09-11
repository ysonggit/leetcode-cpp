class Solution {
public:
    bool binarySearch(vector<int> & nums, int target, int low, int high){
        if(low>high) return false;
        int mid = low+(high-low)/2;
        if(nums[mid]==target) return true;
        bool left = binarySearch(nums, target, low, mid-1);
        bool right = binarySearch(nums, target, mid+1, high);
        return left ? left : right;
    }
    bool search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }
};
