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
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, 
                        int start_pre, int end_pre, int start_in, int end_in)
    {
        if(start_pre > end_pre || start_in > end_in) return NULL;
        int root_val = preorder[start_pre];
        int root_pos = 0;
        for(int i=start_in; i<=end_in; i++){
            if(root_val == inorder[i]){
                root_pos = i;
                break;
            }
        }
        int left_size = root_pos - start_in;
        TreeNode* root = new TreeNode(root_val);
        root->left = construct(preorder, inorder, start_pre+1, start_pre+left_size, start_in, root_pos-1);
        root->right = construct(preorder, inorder, start_pre+left_size+1, end_pre, root_pos+1, end_in);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construct(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
