class WordDistance {
public:
    unordered_map<string, vector<int> > dict;
    WordDistance(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            dict[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int min_dist = INT_MAX;
        for(auto  pos1 : dict[word1]){
            for(auto pos2 : dict[word2]){
                min_dist = min(min_dist, abs(pos1-pos2));
            }
        }
        return min_dist;
    }
};

// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
