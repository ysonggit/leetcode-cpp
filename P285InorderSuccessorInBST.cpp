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
    // assume p is in the BST, iterative version
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> parentStack;
        TreeNode * cur = root;
        while(!parentStack.empty() || cur!=NULL){
            if(cur!=NULL){
                parentStack.push(cur);
                cur = cur->left;
            }else{
                cur = parentStack.top();
                parentStack.pop();
                // visit cur
                if(cur->val > p->val){
                    return cur;
                } 
                cur = cur->right;
            }
        }
        return NULL;
    }
};
