class Solution {
public:
    //  sign, overflow, space
    int myAtoi(string str) {
        int i = str.find_first_not_of(' ');
        if(i==string::npos) return 0; // only spaces
        int sign = 1;
        int n = str.length();
        if(str[i]=='-') {
            sign = -1;
            i++;
            if(i==n) return 0;
            if(!isdigit(str[i])) return 0;
        }
        if(str[i]=='+') {
            i++;
            if(i==n) return 0;
            if(!isdigit(str[i])) return 0;
        }
        int res = 0;
        while(i<n){
            if(!isdigit(str[i])){
                return sign * res;
            }
            // overflow check
            auto cur_digit = (unsigned int)str[i] - (unsigned int)'0';  
            if(res > INT_MAX/10 || (res==INT_MAX/10 && cur_digit > INT_MAX%10)){ // stupid mistake : res > INT_MAX%10 !
                return (sign>0) ? INT_MAX : INT_MIN;
            }
            res = res * 10 + cur_digit;
            i++;
        }
        return sign * res;
    }
};
