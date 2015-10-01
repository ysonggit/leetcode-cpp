class ValidWordAbbr {
public:
    // mistake: ["hello"] isUnique("hello") should return true
    // so can not simply store the word counts
    unordered_map<string, vector<string> > wdLists; 
    ValidWordAbbr(vector<string> &dictionary) {
        for(string wd : dictionary){
            auto n = wd.length();
            if(n==0) continue;
            wdLists[compressWord(wd)].push_back(wd);
        }
    }
    string compressWord(string wd){
        auto n = wd.length();
        if(n<=2) return wd;
        return wd[0]+to_string(n-2)+wd[n-1];
    }
    bool isUnique(string word) {
        string key = compressWord(word);
        return (wdLists[key].size()==0 || (wdLists[key].size()==1 && wdLists[key].back()==word));
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
