class Solution {
public:
    /*
    最烦的题，没有之一！
    return true if: ([ ]*)([+|-]*)([0.]*|[.]*)([0-9]+)([ ]*) or ([ ]*)([+|-]*)([0-9]+)([ ]*)([e|E1][0]+)
    Use method http://leetcodenotes.wordpress.com/2013/11/23/leetcode-valid-number/
    Match pattern :  AeB 
    A could be numbers with/out DOT, with/out sign
    B could be only integer numbers, with/out sign
    AB must exist at the same time if e exists
    */
    // Match A pattern
    bool isNumeric(string a){
        // pass by the first bit. it could be +/-
        if(a.length()>0 && (a[0] =='+' || a[0] =='-'))
            a=a.substr(1);      
        if (a.length() == 0) return false;
        // check dot(s) by removing only one dot
        // after removing, if there are still dots, return false
        size_t dot_pos = a.find(string(".")); // return npos or first idx of .
        if(dot_pos != string::npos){
            a.erase(dot_pos, 1);
            // if no char left after removing one ., then false
            if(a.length()==0) return false; 
        }
        // check rest characters, must be all numeric characters
        for(int i=0; i<a.length(); i++){
            if(!isdigit(a[i])) 
                return false;
        }
        return true;
    }
    // Match B pattern
    bool isInteger(string b){
        if(b.length() == 0 ) return false;
        if(b[0] == '+' || b[0]=='-'){
           b= b.substr(1);
        }
        // check if only -/+ stands
        if(b.length()==0) return false;
        for(int i = 0; i<b.length(); i++){
            if(!isdigit(b[i])) 
                return false;
        }
        return true;
    }
    // DAMN! Cpp is stupid!
    void trim(string & s){
        int i=0, j= s.length()-1;
        while(i<s.length() && s[i]==' ') i++;
        while(j>=0 && s[j]==' ') j--;
        s= s.substr(i, j-i+1);
    }

    bool isNumber(string s) {
        trim(s);
        int N = s.length();
        if(N<=0) return false;
        // 2. check whether e exists
        size_t e_pos = s.find(string("e"));
        // 3e or e9 is invalid
        if(e_pos==0 ||e_pos == N-1 ) return false;
        if(e_pos != string::npos){
            // must match both A & B patterns
            string a = s.substr(0, e_pos);
            string b = s.substr(e_pos+1);
            return isNumeric(a) && isInteger(b);
        }else{
            //no e, match pattern A
            return isNumeric(s);
        }
        return false;
    }
};
