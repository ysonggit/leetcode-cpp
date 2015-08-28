class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        int n = nums.size();
        if(n==0) return res;
        // donot forget to sort first
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++){
            int a = nums[i];
            if(i>0 && nums[i]==nums[i-1]) continue; // remove duplicates
            for(int j=i+1; j<n-2; j++){
                int b = nums[j];
                if(j>i+1 && nums[j]==nums[j-1]) continue; // mistake j>0
                int front = j+1, back = n-1;
                while(front<back){
                    int c = nums[front];
                    int d = nums[back];
                    int sum = a+b+c+d;
                    if(sum == target) {
                        res.push_back(vector<int>{a, b, c, d});
                        // mistake!! front back may not move at all
                        //while(front<back && nums[front]==nums[front+1]) front++;
                        //while(front<back && nums[back-1]== nums[back]) back--;
                        front++;
                        back--;
                        while(front<back && nums[front]==nums[front-1]) front++;
                        while(front<back && nums[back]== nums[back+1]) back--;
                    }else if(sum<target){
                        front++;
                    }else{
                        back--;
                    }
                }
            }
        }
        return res;
    }
};
