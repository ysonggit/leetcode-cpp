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
    bool isUnival(TreeNode * root, int v){
        if(root==nullptr) return true;
        if(root->val != v) return false;
        if(root->left == NULL && root->right==NULL) return true;
        bool left_unival = isUnival(root->left, v);
        bool right_unival = isUnival(root->right, v);
        return left_unival && right_unival;
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        if(root==nullptr) return 0;
        int count = 0;
        if(isUnival(root, root->val)) count++;
        count += countUnivalSubtrees(root->left);
        count += countUnivalSubtrees(root->right);
        return count;
    }
};
