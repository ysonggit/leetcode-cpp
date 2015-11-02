/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy->next;
        ListNode* pre = dummy;
        while(cur!=NULL){
            if(cur->val == val){
                ListNode* to_del = cur;
                pre->next = cur->next;
                delete to_del;
                to_del = NULL;
                cur = pre->next;
            }else{
                cur = cur->next;
                pre = pre->next;
            }
        }
        return dummy->next;
    }
};
