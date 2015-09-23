class Solution {
public:
    void dfs(vector<string> & res, string sol, string s, 
            int start, int count){
        if(count>4) return;
        int n = s.length();
        if(start == n && count==4){
            res.push_back(sol);
            return;
        }
        for(int len=1; len<=min(n-start, 3); len++){
            string segment = s.substr(start, len);
            if(segment[0]=='0' && len>1) return;
            if(stoi(segment)>255) return;
            int pre_size = sol.length();
            sol += (pre_size==0) ? segment : "." + segment;
            dfs(res, sol, s, start+len, count+1);
            sol = sol.substr(0, pre_size);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.length()==0) return res;
        string sol;
        dfs(res, sol, s, 0, 0);
        return res;
    }
};
