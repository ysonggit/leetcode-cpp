class Solution {
public:
    // 1 0 4 2 t=3 k=1 t could be very large: INT_MAX
    // maintains a window of size k using a set
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<int> window;
        int leftmost_pos = 0;
        for(int i=0; i<n; i++){
            if(i- leftmost_pos > k){
                // remove an element while shift leftmost_pos by 1
                window.erase(window.find(nums[leftmost_pos]));
                leftmost_pos++;
            }
            // consider elements from idx leftmost_pos .. i
            int cur = nums[i]; 
            set<int>::iterator low = window.lower_bound(cur-t); // low >= cur - t
            // high <= cur + t. make sure low does not exceed high 
            if(low!= window.end() && (long) (*low) <= (long) cur + (long)t ){
                return true;
            }
            window.insert(cur);
        }
        return false;
    }
};
