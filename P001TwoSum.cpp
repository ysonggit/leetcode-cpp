class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> map;
        for(int i=0; i<n; i++){
            int cur = nums[i];
            if(map.find(target-cur)!=map.end()){
                return vector<int>{map[target-cur], i+1};
            }else{
                map[cur] = i+1;
            }
        }
        return vector<int>();
    }
};
