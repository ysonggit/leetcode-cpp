class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = "";
        if(n==0) return prefix;
        string first = strs[0];
        for(int i=0; i<first.length(); i++){
            char c = first[i];
            for(int j=1; j<n; j++){
                string second = strs[j];
                if(second.length()==i) return prefix;
                if(first[i] != second[i]) return prefix;
            }
            prefix = prefix + c;
        }
        return prefix;
    }
};
