class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int n = nums.size();
        if(n<3) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            while(i>0 && nums[i-1]==nums[i]) i++;
            // call two sum
            int front = i+1, back = n-1;
            while(front<back){
                int sum = nums[i] + nums[front] + nums[back];
                if(sum==0) {
                    vector<int> sol = {nums[i], nums[front], nums[back]};
                    res.push_back(sol);
                    front++;
                    back--;
                    while(front<back && nums[front] == nums[front-1]) front++;
                    while(front<back && nums[back] == nums[back+1]) back--;
                }else if(sum<0){
                    front++;
                }else{
                    back--;
                }
            }
        }
        return res;
    }
};
