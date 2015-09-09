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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode * cur = root;
        while(!s.empty() || cur!= NULL){
            if(cur != NULL){
                res.push_back(cur->val);
                if(cur->right) s.push(cur->right);
                cur = cur->left;
            }else{
                cur = s.top();
                s.pop();
            }
        }
        return res;
    }
};
