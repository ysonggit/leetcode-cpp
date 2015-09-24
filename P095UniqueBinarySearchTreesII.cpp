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
    void bottomUpRecur(vector<TreeNode*> & res, int start, int end){
        if(start>end){
            res.push_back(NULL);
            return;
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode*> left, right;
            bottomUpRecur(left, start, i-1);
            bottomUpRecur(right, i+1, end);
            for(TreeNode * left_root : left){
                for(TreeNode* right_root : right){
                    TreeNode * root = new TreeNode(i);
                    root->left = left_root;
                    root->right = right_root;
                    res.push_back(root);
                }
            }
        }
    }
    vector<TreeNode*> generateTrees(int n) {
       vector<TreeNode*> res;
       bottomUpRecur(res, 1, n);
       return res;
    }
};
