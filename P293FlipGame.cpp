class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        if(s.length()<2) return res;
        for(int i=0; i<s.length()-1; i++){
            char cur = s[i], next = s[i+1];
            if(cur==next && cur=='+') {
                //char flip = (cur=='+') ? '-' : '+'; // mistake: only flip ++ to --
                string sol = s;
                sol[i]=sol[i+1] = '-';
                res.push_back(sol);
            }
        }
        return res;
    }
};
