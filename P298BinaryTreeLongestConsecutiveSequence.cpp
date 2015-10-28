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
    void dfs(TreeNode* root, int pre_len, int& max_len){
        max_len = max(max_len, pre_len);
        if(root==NULL) return;
        if(root->left){
            if(root->left->val - root->val==1) dfs(root->left, pre_len+1, max_len);
            else dfs(root->left, 1, max_len);
        }
        if(root->right){
            if(root->right->val - root->val==1) dfs(root->right, pre_len+1, max_len);
            else dfs(root->right, 1, max_len);
        }
    }
    int longestConsecutive(TreeNode* root) {
        if(root==NULL) return 0;
        int max_len = 0;
        dfs(root, 1, max_len);
        return max_len;
    }
};
