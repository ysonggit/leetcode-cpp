/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    int topDownRecur(TreeNode * cur, int sum){
        if(cur==NULL) return sum;
        sum = sum*10 +cur->val;
        if(cur->left==NULL && cur->right==NULL) return sum;
        if(cur->left==NULL) return topDownRecur(cur->right, sum);
        if(cur->right==NULL) return topDownRecur(cur->left, sum);
        return topDownRecur(cur->left, sum) + topDownRecur(cur->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        return topDownRecur(root, 0);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * DFS with extra space
 */
class Solution2 {
public:
    void dfs(vector<int> & nums, int path, TreeNode* cur){
        if(cur==NULL) return;
        int orig = path;
        path = path*10 + cur->val;
        if(cur->left ==NULL && cur->right==NULL){
            nums.push_back(path);
            return;
        }
        dfs(nums, path, cur->left);
        dfs(nums, path, cur->right);
        path = orig;
    }
    int sumNumbers(TreeNode* root) {
        vector<int> nums;
        dfs(nums, 0, root);
        for(int i: nums) cout<<i<<endl;
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
