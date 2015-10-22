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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root==NULL) return res;
        vector<int> level_vals;
        queue<TreeNode*> Q;
        Q.push(root);
        bool rev_order = false;
        while(!Q.empty()){
            int level_size = Q.size();
            for(int i=0; i<level_size; i++){
                TreeNode * cur = Q.front();
                level_vals.push_back(cur->val);
                Q.pop();
                if(cur->left !=NULL) Q.push(cur->left);
                if(cur->right!=NULL) Q.push(cur->right);
            }
            if(rev_order) reverse(level_vals.begin(), level_vals.end());
            res.push_back(level_vals);
            level_vals.clear();
            rev_order = rev_order ? false : true;
        }
        return res;
    }
};
