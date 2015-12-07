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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*> nodes;
        queue<int> indices;
        map<int, vector<int>> col_vals;
        nodes.push(root);
        indices.push(0);
        while(!nodes.empty()){
            int num = nodes.size();
            for(int k=0; k<num; k++){
                auto cur = nodes.front();
                nodes.pop();
                auto col_idx = indices.front();
                indices.pop();
                col_vals[col_idx].push_back(cur->val);
                if(cur->left){
                    nodes.push(cur->left);
                    indices.push(col_idx-1);
                }
                if(cur->right){
                    nodes.push(cur->right);
                    indices.push(col_idx+1);
                }
            }
        }
        for(auto entry : col_vals){
            res.push_back(entry.second);
        }
        return res;
    }
};
