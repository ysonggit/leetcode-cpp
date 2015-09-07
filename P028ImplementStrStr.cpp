class Solution {
public:
    // Prefix Table T[i] the length of the prefix of s, that is also the suffix of s[0,..,i]
    // initial: T[0] = 0
    vector<int> computePrefixTable(string s){
        int n = s.length();
        vector<int> T(n, 0);
        int i=1, j=0;
        while(i<n){
            if(s[i]==s[j]){
                T[i] = j+1; // fuck! remember it!
                i++;
                j++;
            }else if(j>0){
                j = T[j-1]; //rematch from last matched position
            }else{
                // rematch from begin
                i++;
            }
        }
        return T;
    }
    
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        if(m==0) return 0; // fuck, this should return -1, "" ""
        vector<int> T = computePrefixTable(needle);
        int i=0, j=0;
        while(i<n){
            if(haystack[i]==needle[j]){
                if(j==m-1) return i-j;
                i++;
                j++;
            }else if(j>0){
                i=i - T[j-1];//starting from the next matching position
                j=0;
            }else{
                i++;
            }
        }
        return -1;
    }
};
