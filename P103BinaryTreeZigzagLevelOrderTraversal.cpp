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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root==NULL) return res;
        queue<TreeNode*> Q;
        Q.push(root);
        int curr = 1, next = 0;
        bool left_to_right = true;
        vector<int> cur_vals;
        while(!Q.empty()){
            auto node = Q.front();
            Q.pop();
            curr--;
            cur_vals.push_back(node->val);
            if(node->left){
                next++;
                Q.push(node->left);
            }
            if(node->right){
                next++;
                Q.push(node->right);
            }
            if(curr==0){
                swap(curr, next);
                if(!left_to_right){
                    reverse(cur_vals.begin(), cur_vals.end());
                }
                res.push_back(cur_vals);
                cur_vals.clear();
                left_to_right = left_to_right ? false : true;
            }
        }
        return res;
    }
};
