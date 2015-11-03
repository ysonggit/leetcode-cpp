class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> existed;
        for(int i : nums){
            if(existed.find(i)== existed.end()) existed.insert(i);
            else return true;
        }
        return false;
    }
};
