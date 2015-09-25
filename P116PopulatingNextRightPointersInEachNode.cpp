/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void topDownRecur(TreeLinkNode *node, TreeLinkNode *parent){
        if(node==NULL) return;
        if(parent && node== parent->right) {
            if(parent->next !=NULL) node->next = parent->next->left;
        }
        if(parent && node == parent->left) node->next = parent->right;
        topDownRecur(node->right, node);
        topDownRecur(node->left, node);
    }
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        topDownRecur(root, NULL);
    }
};
