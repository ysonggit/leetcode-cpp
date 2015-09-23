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
    bool inorder(TreeNode * root, TreeNode * & predessesor){ // trick must pass a reference
        if(root==NULL) return true;
        if(!inorder(root->left, predessesor)) return false;
        if(predessesor!=NULL && root->val <= predessesor->val) return false;
        predessesor = root;
        return inorder(root->right, predessesor);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode * predessesor = NULL;
        return inorder(root, predessesor);
    }
};
