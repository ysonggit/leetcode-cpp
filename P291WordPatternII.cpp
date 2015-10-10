class Solution {
public:
    bool isMatch(string & pattern, string & str, 
                int start_pattern_idx, int start_str_idx,
                unordered_map<char, string> forward_mapping){
        if(start_pattern_idx >= pattern.length() && start_str_idx>= str.length())
            return true;
        if(start_pattern_idx >= pattern.length() || start_str_idx >= str.length())
            return false;
        char pc = pattern[start_pattern_idx];
        bool inserted = false;
        for(int len=1; len<=str.length()-start_str_idx; len++){
            string s = str.substr(start_str_idx, len);
            if(forward_mapping.find(pc)==forward_mapping.end()){
                forward_mapping[pc] = s;
                inserted = true;
            }else{
                if(forward_mapping[pc]!=s) continue; // mistake: never return false here
            }
            if(isMatch(pattern, str, start_pattern_idx+1, start_str_idx+len, forward_mapping)){
                return true;
            }
            if(inserted) forward_mapping.erase(pc);
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string str) {
        if(pattern.empty()) return str.empty();
        unordered_map<char, string> forward_mapping;
        return isMatch(pattern, str, 0, 0, forward_mapping);
    }
};
