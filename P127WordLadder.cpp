class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> visited;
        queue<string> Q;
        Q.push(beginWord);
        visited.insert(beginWord);
        int len = 1;
        while(!Q.empty()){
            int cur_level = Q.size();
            for(int k=0; k<cur_level; k++){
                auto wd = Q.front();
                Q.pop();
                for(int i=0; i<wd.length(); i++){
                    char orig = wd[i];
                    for(char c = 'a'; c<='z'; c++){
                        if(c==orig) continue;
                        wd[i] = c;
                        if(visited.find(wd)!= visited.end()) continue;
                        if(wd == endWord) return len+1;
                        if(wordList.find(wd)!= wordList.end()){
                            visited.insert(wd);
                            Q.push(wd);
                        }
                    }
                    wd[i] = orig;
                }
            }
            len++;
        }
        return 0;
    }
};
