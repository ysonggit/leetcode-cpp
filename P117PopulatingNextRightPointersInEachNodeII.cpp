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
    TreeLinkNode* closestRight(TreeLinkNode* node){
        if(node==NULL) return NULL;
        if(node->left) return node->left;
        if(node->right) return node->right;
        return closestRight(node->next);
    }
    void topDownRecur(TreeLinkNode *node, TreeLinkNode *parent){
        if(node==NULL) return;
        if(parent && node== parent->right) {
            node->next = closestRight(parent->next);
        }
        if(parent && node == parent->left) {
            if(parent->right) node->next = parent->right;
            else node->next = closestRight(parent->next);
        }
        topDownRecur(node->right, node);
        topDownRecur(node->left, node);
    }
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        topDownRecur(root, NULL);
    }
};
