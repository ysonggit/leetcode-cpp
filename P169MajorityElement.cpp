class Solution {
public:
    // moore's voting algorithm
    int majorityElement(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int count = 1, maj = nums[0];
        for(int i=1; i< nums.size(); i++){
            if(nums[i]==maj){
                count++;
            }else{
                count--;
            }
            if(count==0){ 
                maj = nums[i];
                count = 1;   
            }
        }
        return maj;
    }
};
