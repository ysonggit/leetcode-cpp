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
    int topDownRecur(TreeNode * cur, int sum){
        if(cur==NULL) return sum;
        sum = sum*10 +cur->val;
        if(cur->left==NULL && cur->right==NULL) return sum;
        if(cur->left==NULL) return topDownRecur(cur->right, sum);
        if(cur->right==NULL) return topDownRecur(cur->left, sum);
        return topDownRecur(cur->left, sum) + topDownRecur(cur->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        return topDownRecur(root, 0);
    }
};
