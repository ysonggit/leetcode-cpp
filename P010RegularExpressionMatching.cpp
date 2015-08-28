class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p=='\0') return *s == '\0';
        // look ahead for *
        if(*(p+1) != '*'){
            // next is not *, then current must match
            if((*p == *s) || (*p=='.'&& *s != '\0')) {
                return isMatch(s+1, p+1);
            }else{
                return false; 
            }
        }else{
            // next is *, then look ahead by 2 steps, match preceeding char
            // s=aab, p=a* should return false
            while(*p==*s || (*p=='.' && *s != '\0')){
                if(isMatch(s, p+2)) return true;
                s++;  // pass by all matched char (to preceeding char) in s 
            }
            return isMatch(s, p+2);
        }
        return false;
    }
    bool isMatch(string s, string p){
        return isMatch(s.c_str(), p.c_str());
    }
};
