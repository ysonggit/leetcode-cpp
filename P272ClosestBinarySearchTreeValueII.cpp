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
    // from jaewoo
    // similar to the top k largest numbers problem, use minheap+binary search
    void dfs(TreeNode* root, double target, int k, 
        priority_queue<pair<double, int> > & heap)
    {
        if(root==NULL) return;
        if(heap.size()<k) heap.push(make_pair(fabs(target - (double)root->val), root->val));
        else{
            if(heap.top().first > fabs(target - (double)root->val)){
                heap.pop();
                heap.push(make_pair(fabs(target- (double)root->val), root->val));
            }
        }
        dfs(root->left, target, k, heap);
        dfs(root->right, target, k, heap);
    }
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        priority_queue<pair<double, int> > heap;
        dfs(root, target, k, heap);
        while(!heap.empty()){
            res.push_back(heap.top().second);
            heap.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
