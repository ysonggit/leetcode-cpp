/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(vector<string>& res, string path, TreeNode* root){
        if(root==NULL) return;
        stringstream ss;
        ss<<root->val;
        string orig = path;
        path += (path.length()==0) ? ss.str() : "->" + ss.str();
        if(root->left == NULL && root->right==NULL){
            res.push_back(path);
            return;
        }
        dfs(res, path, root->left);
        dfs(res, path, root->right);
        path = orig;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;
        dfs(res, path, root);
        return res;
    }
};
