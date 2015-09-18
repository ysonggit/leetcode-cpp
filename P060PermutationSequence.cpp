class Solution {
public:
    // from zxyperfect
    string getPermutation(int n, int k) {
        int permu_table[10] = {1};
        //1 1 2 6 24 120 720 5040 40320 362880
        vector<int> digits;
        for(int i=1; i<=9; i++) {
            permu_table[i] = i* permu_table[i-1];
            digits.push_back(i);
        }
        string res;
        for(int i=n; i>0; i--){
            int j = ((k-1)%permu_table[i])/permu_table[i-1];
            res.push_back((char)digits[j]+'0');
            // remove i-th digit
            digits.erase(digits.begin()+j);
        }
        return res;
    }
};
