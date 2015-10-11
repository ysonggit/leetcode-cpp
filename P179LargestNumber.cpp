class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto comparator = [](const int &a, const int &b){ 
            return to_string(a)+to_string(b) > to_string(b) + to_string(a);
        }; // do not forget this ;
        sort(nums.begin(), nums.end(), comparator);
        string res;
        for(int i : nums) res += to_string(i);
        return res[0]=='0' ? "0" : res; // mistake : "00"
    }
};
