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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vals;
        if(root==NULL) return vals;
        queue<TreeNode*> cur_level;
        cur_level.push(root);
        while(!cur_level.empty()){
            int num = cur_level.size();
            for(int i=0; i<num; i++){
                auto cur = cur_level.front();
                if(i==num-1) vals.push_back(cur->val);
                cur_level.pop();
                if(cur->left) cur_level.push(cur->left);
                if(cur->right) cur_level.push(cur->right);
            }
        }
        return vals;
    }
};
