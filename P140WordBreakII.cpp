class Solution {
public:
    // Define D[i] boolean value representing the first i chars can be segmented
    // D[i] is true if D[k] is true and substring s[k, i-1] is in dict, k is [0, i-1]
    void canBreak(string s, unordered_set<string> & wordDict, bool*& D){
        for(int i=1; i<=s.length(); i++){
            for(int k=0; k<i; k++){
                if(D[k] && (wordDict.find(s.substr(k, i-k)) != wordDict.end())){
                    D[i] = true;
                    break;
                }
            }
        }
    }
    void dfs(vector<string> & res, string s, string path, int cur_idx, 
        unordered_set<string> & wordDict, bool* D){
        if(cur_idx>=s.length()){
            res.push_back(path);
            return;
        }
        for(int len=1; len<= s.length()-cur_idx; len++){
            string cur = s.substr(cur_idx, len); // mistake: start from cur_idx, len = i-cur_idx
            if(wordDict.find(cur)!=wordDict.end() && D[cur_idx+len]){ //mistake: must check D[i]
                int path_len = path.size();
                path += (path_len==0) ? cur : " "+cur;
                dfs(res, s, path, cur_idx+len, wordDict, D);
                path = path.substr(0, path_len);
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        const int n = s.length();
        bool * D = new bool[n+1];
        D[0] = 1;
        canBreak(s, wordDict, D);
        if(!D[n]) return res; // to pass TLE
        string path;
        dfs(res, s, path, 0, wordDict, D);
        delete [] D;
        D = NULL;
        return res;
    }
};
