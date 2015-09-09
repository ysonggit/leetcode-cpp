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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> parents;
        TreeNode * cur = root;
        while(!parents.empty() || cur != NULL){
            if(cur != NULL){
                parents.push(cur);
                cur = cur->left;
            }else{
                cur = parents.top();
                res.push_back(cur->val);
                parents.pop();
                cur = cur->right;
            }
        }
        return res;
    }
};
