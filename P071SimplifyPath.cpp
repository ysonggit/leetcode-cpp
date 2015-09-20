class Solution {
public:
    // trick: use stringstream to split delimiter
    // http://stackoverflow.com/questions/11719538/how-to-use-stringstream-to-separate-comma-separated-strings
    string simplifyPath(string path) {
        string res, token;
        int n = path.length();
        if(n==0) return res;
        vector<string> dirs;
        stringstream ss(path);
        while(getline(ss, token, '/')){
            if(token=="."|| token=="") continue;
            if(token==".." && dirs.size()>0) dirs.pop_back();
            else if(token!="..") dirs.push_back(token);
        }
        for(string name : dirs) res += "/"+name;
        return (dirs.size() == 0) ? "/" : res;
    }
};
