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
    /* Recursive    
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }*/
    // BFS,namely plain level-order traversal
    int maxDepth(TreeNode* root){
        if(root==NULL) return 0;
        int depth = 0;
        queue<TreeNode*> Q;
        int cur_level = 1, nex_level = 0;
        Q.push(root);
        while(!Q.empty()){
            auto cur = Q.front();
            Q.pop();
            cur_level--;
            if(cur->left) {
                Q.push(cur->left);
                nex_level++;
            }
            if(cur->right) {
                Q.push(cur->right);
                nex_level++;
            }
            if(cur_level==0){
                swap(cur_level, nex_level);
                depth++;
            }
        }
        return depth;
    }
};
