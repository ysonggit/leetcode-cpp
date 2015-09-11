class Solution {
public:
    void trim(string & s){
        int n= s.length();
        int i=0, j=n-1;
        while(i<n && s[i]==' ') i++;
        while(j>=0 && s[j]==' ')j--;
        s = s.substr(i, j-i+1);
    }
    
    bool isNumber(string s) {
        trim(s);
        int i=0, n = s.length();
        // if starts from a sign
        if(s[i]=='+'||s[i]=='-') i++;
        bool is_num = false;
        // if starts/follows a number
        while(i<n && isdigit(s[i])){
            i++;
            is_num = true;
        }
        //if starts/follows a dot
        if(i<n && s[i]=='.'){
            i++;
            while(i<n && isdigit(s[i])){
                i++;
                is_num = true;
            }
        }
        // if follows an 'e'
        // if starts from an e then false e9
        if(is_num && i<n && s[i]=='e'){
            // if ends with an e also false  1e
            is_num = false;
            // if any number follows e
            i++;
            // a sign after e is valid : " 005047e+6"
            if(i<n && (s[i]=='+'|| s[i]=='-')) i++;
            while(i<n && isdigit(s[i])){
                i++;
                is_num = true;
            }
        }
        return is_num && i==n;
    }
};
