/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        stack<TreeNode*> s;
        s.push(root);
        string res;
        while(!s.empty()){
            TreeNode * cur = s.top();
            s.pop();
            if(res.length()>0) res +=",";
            if(cur ==NULL) res += "#";
            else{
                res+= to_string(cur->val);
                s.push(cur->right);
                s.push(cur->left);
            }
        }
        return res;
    }
    TreeNode * extractNode(string & s){
        if(s.length()==0) return NULL;
        size_t comma_pos = s.find_first_of(",");
        if(comma_pos==string::npos) {
            // the only node
            if(s == "#") return NULL; // mistake: [1] => 1,#,#
            return new TreeNode(stoi(s));
        }
        string cur = s.substr(0, comma_pos);
        s = s.substr(comma_pos+1);
        if(cur == "#") return NULL;
        TreeNode * root = new TreeNode(stoi(cur));
        root->left = extractNode(s);
        root->right = extractNode(s);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return extractNode(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
