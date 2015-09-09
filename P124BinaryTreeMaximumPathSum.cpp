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
    /**
     * Max sum could be
     * value of node
     * value of node + left subtree sum
     * value of node + right subtree sum
     * left subtree sum + right subtree sum + value of node
     */ 
    int global_max = INT_MIN; // mistake: can not initialize to 0: test case [-3]
   
    int getPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int node_val = root->val;
        int left_sum = getPathSum(root->left);
        int right_sum = getPathSum(root->right);
        int local_max = max({node_val, node_val+left_sum, node_val+right_sum});
        // arc sum does not belong to local 
        global_max = max({local_max, global_max, node_val+left_sum+right_sum});
        return local_max;
    }
    int maxPathSum(TreeNode * root){
        if(root==NULL) return 0;
        getPathSum(root);
        return global_max;
    }
};
