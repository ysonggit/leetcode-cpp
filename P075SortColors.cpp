class Solution {
public:
    // trick: maintain and update the last position of each color
    // from flying_birdman
    void sortColors(vector<int>& nums) {
        int r=0, w=0, b=0;;
        for(int color : nums){
            if(color==0){ 
                nums[b++]=2; 
                nums[w++]=1;
                nums[r++]=0;
            }else if(color==1){
                nums[b++]=2;
                nums[w++]=1;
            }else{
                b++;
            }
        }
    }
};
