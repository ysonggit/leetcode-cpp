class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> num_pos; // mistake: should save all appeared indices [1 0 1 1] k = 3
        for(int i=0; i<nums.size(); i++){
            if(num_pos.find(nums[i])==num_pos.end()){
                num_pos[nums[i]] = vector<int>{i};
            }else{
                for(int j : num_pos[nums[i]]){
                    if(i-j<=k) return true;
                }
                num_pos[nums[i]].push_back(i);
            }
        }
        return false;
    }
};
