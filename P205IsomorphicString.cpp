class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length(), m = t.length();
        if(n==0) return m==0;
        if(m != n)  return false;
        unordered_map<char, char> forward, backward;
        for(int i=0; i<n; i++){
            if(forward.find(s[i])==forward.end()){
                forward[s[i]] = t[i];
            }else{
                if(forward[s[i]]!=t[i]) return false;
            }
            if(backward.find(t[i])==backward.end()){
                backward[t[i]] = s[i];
            }else{
                if(backward[t[i]]!=s[i]) return false;
            }
        }
        return true;
    }
};
