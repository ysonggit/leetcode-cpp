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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        if(root->left == NULL && root->right==NULL) return root;
        TreeNode * left_cp = root->left;
        TreeNode * right_cp = root->right;
        root->left = invertTree(right_cp);
        root->right = invertTree(left_cp);
        return root;
    }
};
