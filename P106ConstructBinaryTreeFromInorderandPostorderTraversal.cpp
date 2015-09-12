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
    // last num in post order is the root
    // find the root pos in inorder seq, divide and conquer
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return construct(inorder, postorder, 0, n-1, 0, n-1);
    }
    
    TreeNode* construct(vector<int>& inorder, 
                            vector<int>& postorder, 
                            int start_in, int end_in, 
                            int start_post, int end_post)
    {
            if(start_in > end_in || start_post > end_post) return NULL;
            int root_val = postorder[end_post];
            // can use a hashmap O(1) instead of linear search (n)
            int root_pos = 0;
            for(int i= start_in; i<= end_in; i++){
                if(inorder[i]==root_val) {
                    root_pos = i;
                    break;
                }
            }
            int left_size = root_pos - start_in;
            TreeNode * root = new TreeNode(root_val);
            root->left = construct(inorder, postorder, start_in, root_pos-1, start_post, start_post+left_size-1);
            root->right= construct(inorder, postorder, root_pos+1, end_in, start_post+left_size, end_post-1);
            return root;
    }
};
