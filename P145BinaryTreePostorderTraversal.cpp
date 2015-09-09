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
     * http://articles.leetcode.com/2010/10/binary-tree-post-order-traversal.html
     *  Push the root node to the first stack.
     *  Pop a node from the first stack, and push it to the second stack.
     *  Then push its left child followed by its right child to the first stack.
     *  Repeat step 2) and 3) until the first stack is empty.
     *  Once done, the second stack would have all the nodes ready to be traversed in post-order. 
     *  Pop off the nodes from the second stack one by one and you’re done.
     */ 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        stack<TreeNode*> first, second;
        first.push(root);
        while(!first.empty()){
            auto cur = first.top();
            first.pop();
            second.push(cur);
            if(cur->left) first.push(cur->left);
            if(cur->right) first.push(cur->right);
        }
        while(!second.empty()){
            res.push_back(second.top()->val);
            second.pop();
        }
        return res;
    }
};
