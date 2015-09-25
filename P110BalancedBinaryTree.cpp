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
    int treeHeight(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(treeHeight(root->left), treeHeight(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int diff = abs(treeHeight(root->left)-treeHeight(root->right) );
        if(diff>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
