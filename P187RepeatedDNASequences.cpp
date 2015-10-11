class Solution {
public:
    // from Debanjan.Chanda
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.length()<10) return res;
        std::hash<string> str_hash; //alternative hash func: A-00 C-01 G-01 T-11
        unordered_map<unsigned int, int> counts;
        for(int i=0; i<=s.length()-10; i++){
            string seq = s.substr(i, 10);
            auto key = str_hash(seq);
            counts[key]++;
            if(counts[key]==2 ) res.push_back(seq);
        }
        return res;
    }
};
