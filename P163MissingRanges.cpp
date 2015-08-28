class Solution {
public:
    string generateRange(int start, int end){
        stringstream ss;
        if(start==end) {
            ss<<start;
            return ss.str();
        }
        ss<<start<<"->"<<end;
        return ss.str();
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int lower_bound = lower -1;
        for(int i : nums){
            if(i - lower_bound>1){
                res.push_back(generateRange(lower_bound+1, i-1));
            }
            lower_bound = i;
        }
        if (nums.size()==0 || (nums.size()>0 && upper>nums.back())){
            res.push_back(generateRange(lower_bound+1, upper));
        } 
        return res;
    }
};
