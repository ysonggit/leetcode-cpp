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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(root==NULL) return res;
        vector<int> level_vals;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            int level_size = Q.size();
            for(int i=0; i<level_size; i++){
                TreeNode * cur = Q.front();
                level_vals.push_back(cur->val);
                Q.pop();
                if(cur->left !=NULL) Q.push(cur->left);
                if(cur->right!=NULL) Q.push(cur->right);
            }
            res.push_back(level_vals);
            level_vals.clear();
        }
        reverse(res.begin(), res.end());
        return res; 
    }
};
