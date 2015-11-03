class Solution1 {
public:
    // minheap O(k) space, O(nlogk) time
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::greater<int>> minheap; // size of k
        int n = nums.size();
        if(n==0) return 0;
        for(int i=0; i<k; i++){
            minheap.push(nums[i]);
        }
        for(int i=k; i<n; i++){
            if(nums[i]> minheap.top()){
                minheap.pop();
                minheap.push(nums[i]);
            }
        }
        return minheap.top();
    }
};

class Solution2 {
public:
    // maxheap O(n) space O(klogn + n) time
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return 0;
        priority_queue<int, vector<int>, std::less<int>> maxheap; // can use make_heap
        for(int i : nums) maxheap.push(i);
        for(int i=0; i<k-1; i++) maxheap.pop();
        return maxheap.top();
    }
};
