class Solution {
public:
    // from jiuzhang
    // http://www.jiuzhang.com/solutions/word-ladder-ii/
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> res;
        unordered_map<string, vector<string> > tree;
        unordered_map<string, int> distance;
        wordList.insert(beginWord);
        wordList.insert(endWord);
        bfs(tree, distance, beginWord, endWord, wordList);
        vector<string> path;
        dfs(res, path, endWord, beginWord, distance, tree);
        return res;
    }
    void bfs(unordered_map<string, vector<string> > & tree, unordered_map<string, int> & distance, 
            string beginWord, string endWord, unordered_set<string> & wordList){
        queue<string> Q;
        Q.push(beginWord);
        distance[beginWord]=0;
        for(string s: wordList){
            tree[s] = vector<string>{};
        }
        while(!Q.empty()){
            string cur = Q.front();
            Q.pop();
            vector<string> next_list;
            for(int i=0; i<cur.length(); i++){
                for(char c='a'; c<='z'; c++){
                    if(c!=cur[i]) {
                        string next = cur.substr(0,i)+c+cur.substr(i+1);
                        if(wordList.find(next)!= wordList.end()){
                            next_list.push_back(next);
                        }
                    }
                }
            }
            for(string next : next_list){
                tree[next].push_back(cur);
                if(distance.find(next)== distance.end()){
                    distance[next] = distance[cur]+1;
                    Q.push(next);
                }
            }
        }
    }
    void dfs(vector<vector<string> >&res, vector<string> path, string cur, string beginWord, 
            unordered_map<string, int> & distance, unordered_map<string, vector<string>>& tree){
        path.push_back(cur);
        if(cur == beginWord){
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
        }else{
            for(string next : tree[cur]){
                if(distance.find(next) != distance.end() && distance[cur]==distance[next]+1){
                    dfs(res, path, next, beginWord, distance, tree);
                }
            }
        }
        path.pop_back();
    }
    
};
