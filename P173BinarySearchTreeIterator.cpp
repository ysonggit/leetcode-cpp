/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    // inorder iterator
    stack<TreeNode*> successors;
    BSTIterator(TreeNode *root) {
        while(root!=NULL){
            successors.push(root);
            root = root->left;
        } 
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !successors.empty();
    }

    /** @return the next smallest number */
    int next() {
        if(successors.empty()) return 0;
        TreeNode* cur = successors.top();
        successors.pop();
        int val = cur->val;
        if(cur->right!=NULL){
            cur = cur->right;
            while(cur!=NULL){
                successors.push(cur);
                cur = cur->left;
            }
        }
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
