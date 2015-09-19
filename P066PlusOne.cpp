class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry =0, n=digits.size();
        for(int i=n-1; i>=0; i--){
            int cur = digits[i];
            int sum = cur + carry;
            if(i==n-1){
                sum += 1;
            }
            digits[i] = sum%10;
            carry = sum/10;
        }
        if(carry>0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
