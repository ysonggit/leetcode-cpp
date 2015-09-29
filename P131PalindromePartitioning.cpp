class Solution {
public:
    bool isPalindrome(string s){
        int front=0, back = s.length()-1;
        while(front<back){
            if(s[front]!=s[back]) return false;
            front++;
            back--;
        }
        return true;
    }
    void dfs(vector<vector<string>> & res, string s, 
            vector<string> sol, int cur_idx){
        if(cur_idx == s.length()){
            res.push_back(sol);
            return;
        } 
        for(int len=1; len<=s.length()-cur_idx; len++){
            string cur = s.substr(cur_idx, len);
            if(isPalindrome(cur)){
                sol.push_back(cur);
                dfs(res, s, sol, cur_idx+len); // mistake cur_idx+len not +1
                sol.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        if(s.length()==0) return res;
        vector<string> sol;
        dfs(res, s, sol, 0);
        return res;
    }
};
