class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        is_word = false;
        children = unordered_map<char, TrieNode*>{};
    }
    bool is_word;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        for(char c: word){
            if(cur->children.find(c)==cur->children.end()){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        for(char c: word){
            if(cur->children.find(c)==cur->children.end()) return false;
            cur = cur->children[c];
        }
        return cur->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char c: prefix){
            if(cur->children.find(c)==cur->children.end()) return false;
            cur = cur->children[c];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
