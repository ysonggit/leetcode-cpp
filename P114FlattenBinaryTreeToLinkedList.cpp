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
    // each node's right child points to the next node of a pre-order traversal.
    // from phu1ku
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        flatten(root->left);
        flatten(root->right);
        // 1. backup right child
        TreeNode* right_cp = root->right;
        // 2. connect left subtree to root's right
        root->right = root->left;
        // 3. null left child
        root->left = NULL;
        // 4. connect right_cp to the tail of pre-order succ
        while(root->right!=NULL) root=root->right;
        root->right = right_cp;
    }
};
