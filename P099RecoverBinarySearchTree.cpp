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
    // from siyang3
    void recoverTree(TreeNode* root) {
        TreeNode * cur = NULL;
        TreeNode * pre = NULL;
        TreeNode * first = NULL;
        TreeNode * second = NULL;
        while(root!=NULL){
            if(root->left !=NULL){
                cur = root->left;
                while(cur->right!=NULL && cur->right!=root){
                    cur = cur->right;
                }
                if(cur->right!=NULL){ // threading already there
                    cur->right = NULL; // traversal right subtree of root
                    if(pre!=NULL && pre->val > root->val){
                        if(first==NULL) first = pre;
                        second = root;
                    }
                    pre = root; // backup root
                    root = root->right;
                }else{  // connect a threading to the root
                    cur->right = root;  // continue traversal from left subtree
                    root = root->left;
                }
            }else{
                if(pre!=NULL && pre->val > root->val){
                    if(first == NULL) first = pre;
                    second = root;
                }
                pre = root;
                root=root->right;
            }
        }
        // swap two mis-ordered nodes
        swap(first->val, second->val);
    }
};
