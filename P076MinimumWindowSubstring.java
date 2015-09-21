class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length(), n=t.length();
        if(m<n) return "";
        vector<int> dict_t(256,0);
        vector<int> dict_s(256,0);
        for(char c : t) dict_t[c]++;
        int min_len = m+1;
        int start = 0, count=0, min_window_start=0;
        for(int i=0; i<m; i++){
            char cur = s[i];
            if(dict_t[cur]==0) continue;
            if(dict_t[cur] > dict_s[cur]) count++;
            dict_s[cur]++;
            while(count==n){
                if(dict_s[s[start]]==0){
                    start++;
                }else if(dict_s[s[start]]>dict_t[s[start]]){
                    dict_s[s[start]]--;
                    start++; // fuck! decrease first then increase start!!
                }else{
                    if(min_len > i-start+1){
                        min_len = i-start+1;
                        min_window_start = start;
                    }
                    break; // IMPORTANT
                }   
            }
        }
        return (min_len > m) ? "" : s.substr(min_window_start, min_len);
    }
};
