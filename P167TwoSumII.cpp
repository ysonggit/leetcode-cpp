class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int front = 0, back = n-1;
        while(front<back){
            int sum = numbers[front]+numbers[back];
            if(sum==target){
                return vector<int>{front+1, back+1};
            }else if(sum < target){
                front++;
            }else{
                back--;
            }
        }
        return vector<int>{};
    }
};
