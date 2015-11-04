class Solution {
public:
    // DFS TLE
    // BFS idea from jeantimex
    bool isValid(string s){
        if(s.empty()) return true;
        stack<char> left_parens;
        for(char c : s){
            if(c=='(') left_parens.push(c);
            else if(c==')'){
                if(left_parens.empty()) return false;
                else left_parens.pop();
            }else continue;
        }
        return left_parens.empty() ? true : false;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited; // set -> TLE
        queue<string> Q;
        Q.push(s);
        int max_len = 0;
        while(!Q.empty()){
            string cur = Q.front();
            Q.pop();
            if(isValid(cur)){
                if(cur.length() >= max_len) res.push_back(cur);
                max_len = max(max_len, (int)cur.length());
            }
            for(int i=0; i<cur.length(); i++){
                if(cur[i]!=')'&& cur[i]!='(') continue;
                // remove one '(' or ')'
                string next = cur.substr(0, i)+cur.substr(i+1);
                if(visited.find(next)==visited.end()){
                    visited.insert(next);
                    Q.push(next);
                }
            }
        }
        if(res.size()==0 && max_len==0) res.push_back("");
        return res;
    }
};
