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
    int closest_sofar = INT_MAX;
    bool doubleEqual(double a, double b){
        return abs(a-b) <= std::numeric_limits<double>::epsilon();
    }
    int closestValue(TreeNode* root, double target) {
        if(root==nullptr) return closest_sofar;
        int cur = root->val;
        if(doubleEqual((double)cur, target)) return root->val;
        // update global closest value if current val produces smaller diff
        if(closest_sofar == INT_MAX || abs(closest_sofar - target) > abs(cur-target)){
            closest_sofar = cur;
        }
        if(cur>target) return closestValue(root->left, target);
        return closestValue(root->right, target);
    }
};
