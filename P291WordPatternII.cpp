class Solution {
public:
    bool isMatch(string & pattern, string & str, 
                int start_pattern_idx, int start_str_idx,
                unordered_map<char, string> forward_mapping,
                unordered_map<string, char> backward_mapping){
        if(start_pattern_idx >= pattern.length() && start_str_idx>= str.length())
            return true;
        if(start_pattern_idx >= pattern.length() || start_str_idx >= str.length())
            return false;
        char pc = pattern[start_pattern_idx];
        bool inserted_forward = false, inserted_backward = false;
        for(int len=1; len<=str.length()-start_str_idx; len++){
            string s = str.substr(start_str_idx, len);
            if(forward_mapping.find(pc)==forward_mapping.end()){
                forward_mapping[pc] = s;
                inserted_forward = true;
            }else{
                if(forward_mapping[pc]!=s) continue;
            }
            if(backward_mapping.find(s)==backward_mapping.end()){
                backward_mapping[s] = pc;
                inserted_backward = true;
            }else{
                if(backward_mapping[s]!=pc) return false;
            }
            if(isMatch(pattern, str, start_pattern_idx+1, start_str_idx+len, forward_mapping, backward_mapping)){
                return true;
            }
            if(inserted_forward) forward_mapping.erase(pc);
            if(inserted_backward) backward_mapping.erase(s);
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string str) {
        if(pattern.empty()) return str.empty();
        unordered_map<char, string> forward_mapping;
        unordered_map<string, char> backward_mapping;
        return isMatch(pattern, str, 0, 0, forward_mapping, backward_mapping);
    }
};
