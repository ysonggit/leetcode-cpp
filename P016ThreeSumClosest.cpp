class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<3) return 0;
        sort(nums.begin(), nums.end());
        int min_diff_sofar = INT_MAX;
        int closest_sum = 0;
        for(int i=0; i<n-2; i++){
            while(i>0 && nums[i-1]==nums[i]) i++;
            // call two sum
            int front = i+1, back = n-1;
            while(front<back){
                int sum = nums[i] + nums[front] + nums[back];
                int diff = abs(target-sum);
                if(min_diff_sofar> diff){
                    min_diff_sofar = diff;
                    closest_sum = sum;
                }
                if(sum==target) {
                    return target;
                }else if(sum<target){
                    front++;
                }else{
                    back--;
                }
            }
        }
        return closest_sum;
    }
};
