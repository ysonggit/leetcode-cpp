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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        int cur_level = 1, nex_level=0;
        vector<int> cur_level_vals;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            cur_level--;
            cur_level_vals.push_back(cur->val);
            if(cur->left) {
                q.push(cur->left);
                nex_level++;
            }
            if(cur->right){
                q.push(cur->right);
                nex_level++;
            }
            if(cur_level==0){
                swap(cur_level, nex_level);
                res.push_back(cur_level_vals);
                cur_level_vals.clear();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
