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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
       if(!root) return NULL;
       if(!root->left && !root->right) return root;
       TreeNode * right_cp;
       TreeNode * left_cp;
       TreeNode * parent = NULL;
       TreeNode * right_sibling = NULL;
       TreeNode * cur = root;
       while(cur != NULL){
           right_cp = cur->right;
           left_cp = cur->left;
           cur->right= parent;
           cur->left = right_sibling;
           parent = cur;
           right_sibling = right_cp;
           cur = left_cp;
       }
       return parent;
    }
};
