class Solution {
public:
    string addBinary(string a, string b) {
        string sum;
        int i = a.length()-1, j=b.length()-1;
        int carry = 0; // carry_out
        while(i>=0 || j>=0){
            int a_ = (i>=0) ? (a[i]-'0') : 0;
            int b_ = (j>=0) ? (b[j]-'0') : 0;
            int c_ = a_ + b_ + carry;
            carry = c_/2;
            char c = (char) (c_%2 + '0');
            sum.push_back(c);
            i--;
            j--;
        }
        if(carry>0) sum.push_back('1');
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
