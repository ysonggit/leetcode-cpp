class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        vector<int> res;
        if(words.size()==0) return res;
        int m = words[0].length();
        int concat_len = m * (int) words.size();
        if(n < concat_len) return res;
        // build dictionary
        unordered_map<string, int> dict;
        for(string wd : words) dict[wd]++;
        // linear forward search string
        for(int i=0; i<n-concat_len+1; i++){ // mistake on terminating idx : i<n-concat_len
            unordered_map<string, int> dict_cp (dict);
            int count = 0;
            for(int j=i; j<i+concat_len; j+= m){
                string cur = s.substr(j, m);
                if(dict_cp.find(cur) == dict_cp.end()) break;
                if(dict_cp[cur]<=0) break;
                dict_cp[cur]--;
                count++;
            }
            if(count == words.size()) {
                res.push_back(i);
            }
        }
        return res;
    }
};
