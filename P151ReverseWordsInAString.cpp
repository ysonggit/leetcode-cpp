class Solution {
public:
    void reverseWords(string &s) {
        stringstream ss(s);
        string wd;
        string rev;
        while(getline(ss, wd, ' ')){
            if(wd.length()==0) continue;
            rev.insert(0, wd);
            rev.insert(0, " ");
        }
        s = rev.empty() ? "" : rev.substr(1); // mistake: special case rev=""
    }
};
