class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length() + num2.length();
        if(n==0) return "";
        vector<int> mult(n,0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i=0; i<num1.length(); i++){
            int a = (int)(num1[i]-'0');
            for(int j=0; j<num2.length(); j++){
                int b=(int)(num2[j]-'0');
                mult[i+j] += a*b;
                mult[i+j+1] += mult[i+j]/10;
                mult[i+j] %=10;
            }
        }
        string res;
        for(int i : mult){
            res.push_back((char)(i+'0'));
        }
        reverse(res.begin(), res.end());
        // filter leading 0s
        auto non_zero = res.find_first_not_of('0');
        return (non_zero==string::npos) ? "0" : res.substr(non_zero);
    }
};
