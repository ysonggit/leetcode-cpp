class Solution {
public:
    struct TrieNode{
        TrieNode(): is_word(false) {}
        bool is_word;
        unordered_map<char, TrieNode*> children;
    };
    struct Trie{
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
        void insert(string word){
            TrieNode* cur = root;
            for(int i=0; i<word.length(); i++){
                char c = word[i];
                if(cur->children.find(c)==cur->children.end()) {
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
            }
            cur->is_word = true;
        }
    };
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    void dfs(vector<string>& res, vector<vector<char>>& board, TrieNode* root, 
            string path, int i, int j){
        int m = board.size(), n = board[0].size();
        if(i==m||j==n||i<0||j<0) return;
        if(board[i][j]=='\0') return;
        char cur = board[i][j];
        if(root->children.find(cur)==root->children.end()) return;
        path.push_back(cur);
        if(root->children[cur]->is_word){ // mistake: may contains duplicates ["aa"] ["a"]
            if(find(res.begin(), res.end(), path) ==res.end()){
                res.push_back(path);
            }
            // mistake: can not return
        }
        board[i][j] = '\0'; // important! mark visited!
        for(int k=0; k<4; k++){
            dfs(res, board, root->children[cur], path, i+dx[k], j+dy[k]);
        }
        board[i][j] = cur;
        path.pop_back();
    }
    //bool start = false; // for debugging purpose
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(board.size()==0 || words.size()==0) return res;
        Trie trie;
        for(string word : words){
            trie.insert(word);
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                string path;
                dfs(res, board, trie.root, path, i, j);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
