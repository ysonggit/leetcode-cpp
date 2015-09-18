class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        if(strs.size()==0) return res;
        unordered_map<string, vector<string> > dict;
        for(int i=0; i< strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(dict.find(s)==dict.end()){
                dict[s] = vector<string>{};
            }
            dict[s].push_back(strs[i]);    
        }
        for(auto iter = dict.begin(); iter!= dict.end(); ++iter){
            sort(iter->second.begin(), iter->second.end());
            res.push_back(iter->second);
        }
        return res;
    }
};
