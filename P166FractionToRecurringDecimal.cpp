class Solution {
public:
    /**
     * 1. sign;
     * 2. overflow handle (long long) numerator = INT_MIN, denominator = -1
     * 3. numerator/denominator 0
     */ 
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        if(denominator==0) return "NaN";
        string sign = ((numerator^denominator) >= 0) ? "" : "-"; // note: >= has higher priority than ^!
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);
        string int_part = to_string(n/d);
        bool has_frac = (n%d==0) ? false : true;
        string frac;
        if(has_frac){
            frac += ".";
            unordered_map<long long, int> rem_pos;
            auto rem = n % d;
            while(rem != 0){
                if(rem_pos.find(rem) != rem_pos.end()){
                    int recur_start = rem_pos[rem];
                    string non_recur = frac.substr(0, recur_start);
                    string recur = frac.substr(recur_start);
                    return sign+int_part+non_recur + "("+recur+")";
                }
                rem_pos[rem] = frac.length();
                frac += to_string(rem* 10 /d); // think carefully here
                rem = (rem*10)%d;
            }
        }
        return sign+int_part+frac;
    }
};
