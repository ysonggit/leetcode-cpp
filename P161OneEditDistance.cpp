class Solution {
public:
    // Must be exactly one distance apart. same then return false 
    bool isOneEditDistance(string s, string t) {
        int s_len = s.length(), t_len = t.length();
        if(abs(s_len-t_len)>1) return false;
        if(s_len > t_len) return isOneEditDistance(t, s);
        for(int i=0; i<s_len; i++){
            if(s[i]==t[i]) continue;
            if(s_len == t_len){
                // check if already reach the last char
                return (i+1 == s_len ) ? true : s.substr(i+1) == t.substr(i+1);
            }else{
                // s="ac" t="adc"
                return s.substr(i) == t.substr(i+1) ;
            }
        }
        return (s_len==t_len) ? false : true; // s="", t="a" s="", t=""
    }
};
