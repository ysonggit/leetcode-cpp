/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = dummy;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            pre = slow;
            slow =slow->next;
        }
        ListNode* right = slow->next;
        slow->next  = NULL;
        pre->next = NULL;
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(dummy->next);
        root->right = sortedListToBST(right);
        return root;
    }
};
