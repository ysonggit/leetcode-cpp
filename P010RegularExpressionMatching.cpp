class Solution1 {
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

class Solution2 {
public:
    /**
    * '*' match 0 or more preceding sequence
    */
    bool isMatch(string s, string p) {
        const int n = s.length(), m = p.length();
        if(m==0) return n==0;
        bool ** D = new bool*[n+1];
        for(int i=0; i<=n; i++){
            D[i] = new bool[m+1];
            for(int j=0; j<=m; j++){
                D[i][j] = false;
            }
        }
        D[0][0] = true;
        D[0][1] = (p[0]=='*');
        // initialize D[0][j] = D[0][j-2] if p[j-1]=='*'
        for(int j=2; j<=m; j++){
            if(p[j-1]=='*') D[0][j] = D[0][j-2];
        }
        for(int i=1; i<=n; i++){
            char sc = s[i-1];
            for(int j=1; j<=m; j++){
                char pc = p[j-1];
                if(pc!='*'){
                    D[i][j] = (D[i-1][j-1] && (sc==pc|| pc=='.'));
                }else{
                    // check preceding char in p, if . or not
                    if(j>=2){
                        if(p[j-2]=='.'){
                            // similar to wildcard matching but consider one more previous step
                            if(D[i][j-1] || D[i][j-2]){
                                for(int k=i; k<=n; k++) D[k][j] = true;
                            }
                        }else{
                            D[i][j] = D[i][j-1] || D[i][j-2];
                            // also consider one more previous step of s
                            if(i>=2){
                                D[i][j] = D[i][j] || (D[i-1][j] && sc==s[i-2] && s[i-2] == p[j-2]);
                            }
                        }
                    }
                }
            }
        }
        if(false){
            for(int i=0; i<=n; i++){
                for(int j=0; j<=m; j++){
                    if(D[i][j]) cout<<"1 |";
                    else cout<<"0 |";
                }
                cout<<endl;
            }
        }
        return D[n][m];
    }
};
