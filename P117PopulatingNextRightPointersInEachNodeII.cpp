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
    TreeLinkNode* topDownRecur(TreeLinkNode *node, TreeLinkNode *parent){
        if(node==NULL) return NULL;
        if(parent && node== parent->right) {
            node->next = closestRight(parent->next);
        }
        if(parent && node == parent->left) {
            if(parent->right) node->next = parent->right;
            else node->next = closestRight(parent->next);
        }
        node->right = topDownRecur(node->right, node);
        node->left = topDownRecur(node->left, node);
        return node;
    }
    void connect(TreeLinkNode *root) {
        root = topDownRecur(root, NULL);
    }
};
