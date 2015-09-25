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
    void dfs(vector<vector<int>> & res, vector<int> path,
            TreeNode * root, int sum){
        if(root==NULL) return;
        if(root->val == sum && root->left ==NULL && root->right==NULL){
            path.push_back(root->val);
            res.push_back(path);
            return; 
        }
        sum -= root->val;
        path.push_back(root->val);
        dfs(res, path, root->left, sum);
        dfs(res, path, root->right, sum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res; 
        vector<int> path;
        dfs(res, path, root, sum);
        return res;
    }
};
