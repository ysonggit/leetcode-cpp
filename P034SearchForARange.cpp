class Solution {
public:
    vector<int> binarySearch(vector<int> & nums, int target, int low, int high){
        if(low>high) return vector<int>{-1, -1}; // mistake : low >= high
        int mid = low + (high-low)/2;
        if(nums[mid]==target){
            int left = mid-1, right= mid+1;
            while(left >=0 && nums[left]== target) left--;
            while(right<nums.size() && nums[right]==target) right++;
            return vector<int>{left+1, right-1};
        }else if(nums[mid]<target){
            return binarySearch(nums, target, mid+1, high);
        }else{
            return binarySearch(nums, target, low, mid-1);
        }
        return vector<int>{-1, -1};
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size());
    }
};
