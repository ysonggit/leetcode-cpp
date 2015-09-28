class Solution {
public:
    // from Keith Schwarz (htiek@cs.stanford.edu)
    // http://keithschwarz.com/interesting/code/?dir=find-duplicate
    // Simply, treat the array as a linked list with a cycle
    // use two pointers to detect the cycle (duplicates)
    // and find the begining of the cycle 
    // so, similar to the problem "linked list cycle II" 
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = 0, fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break; // cycle found
        }
        // reset fast to the first pos
        fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast) return slow;
        }
        return 0;
    }
};
