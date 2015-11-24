class Solution {
public:
    class BigInteger{
    public:
        string val;
        BigInteger() : val(""){}
        BigInteger(string s) : val(s){}
        friend BigInteger operator+(const BigInteger& b1, const BigInteger& b2){
            string a = b1.val, b = b2.val;
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            string sum;
            int carry = 0;
            for(int i=0; i<max(a.length(), b.length()); i++){
                int j = (i>= a.length()) ? 0 : (a[i]-'0');
                int k = (i>= b.length()) ? 0 : (b[i]-'0');
                int ab = carry + j + k;
                carry = ab/10;
                char c = (char)((int)'0'+ ab%10);
                sum += c;
            }
            if(carry==1) sum += '1';
            reverse(sum.begin(), sum.end());
            return BigInteger(sum);
        }
        friend bool operator==(const BigInteger& b1, const BigInteger& b2){
            if(b1.val.length()!=b2.val.length()) return false;
            for(int i=0; i< b1.val.length(); i++){
                if(b1.val[i]!=b2.val[i]) return false;
            }
            return true;
        }
    };
    
    bool dfs(string num, vector<BigInteger> & seq, int pos){
        if(pos==num.length()){
            return (seq.size()<3) ? false : true;
        }
        for(int i=pos; i<num.length(); i++){
            string cur = num.substr(pos, i+1-pos);
            if(cur.length()>1 && cur[0]=='0') break;
            int n = seq.size();
            BigInteger bi = BigInteger(cur);
            if(n<2 || (n>=2 && bi == seq[n-1] + seq[n-2])){
                seq.push_back(bi);
                if(dfs(num, seq, i+1)) return true;
                else seq.pop_back();
            }
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        if(num.empty()) return false;
        vector<BigInteger> seq;
        return dfs(num, seq, 0);
    }
};
