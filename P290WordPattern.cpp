class Solution {
public:
    // a variety of isomorphic strings problem
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        string token;
        vector<string> tokens;
        while(getline(ss, token, ' ')){
            tokens.push_back(token);
        }
        if(tokens.size()!= pattern.length()) return false;
        unordered_map<char, string> forward_mapping;
        unordered_map<string, char> backward_mapping;
        for(int i=0; i<pattern.size(); i++){
            char c = pattern[i];
            string s = tokens[i];
            if(forward_mapping.find(c)== forward_mapping.end()){
                forward_mapping[c] = s;
            }else{
                if(forward_mapping[c]!=s) return false;
            }
            if(backward_mapping.find(s)==backward_mapping.end()){
                backward_mapping[s] = c;
            }else{
                if(backward_mapping[s]!=c) return false;
            }
        }
        return true;
    }
};
