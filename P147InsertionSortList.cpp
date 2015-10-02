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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy->next;
        while(cur!=NULL && cur->next!=NULL){
            if(cur->val <= cur->next->val){
                cur= cur->next;
            }else{
                ListNode* to_insert = cur->next;
                cur->next = cur->next->next;
                ListNode* pre = dummy;
                while(pre->next != NULL && pre->next->val < to_insert->val){
                    pre = pre->next;
                }
                to_insert->next = pre->next;
                pre->next = to_insert;
            }
        }
        return dummy->next;
    }
};
