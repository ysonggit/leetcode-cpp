class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int low, int high){
        if(low>high) return -1;
        int mid = low+(high-low)/2;
        if(nums[mid]==target) return mid;
        else{
            int left = binarySearch(nums, target, low, mid-1);
            int right = binarySearch(nums, target, mid+1, high);
            return (left >=0 ) ? left : right;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }
};
