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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left ==NULL && root->right==NULL) return 1;
        int left_level = 0, right_level=0;
        TreeNode* left = root;
        while(left !=NULL){
            left_level++;
            left = left->left;
        }
        TreeNode* right = root;
        while(right!=NULL){
            right_level++;
            right = right->right;
        }
        if(left_level == right_level) return pow(2, left_level)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
