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
    TreeNode* topDownRecur(vector<int> & nums, int start, int end){
        if(start>=end) return NULL;
        int mid = start + (end-start)/2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = topDownRecur(nums, start, mid);
        root->right = topDownRecur(nums, mid+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return topDownRecur(nums, 0, nums.size());
    }
};
