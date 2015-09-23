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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL|| head->next == NULL) return head;
        ListNode * dummy= new ListNode(-1);
        dummy->next = head;
        ListNode * pre = dummy;
        ListNode * cur = pre->next;
        while(cur->next != NULL){
            ListNode * nex_cp = cur->next;
            cur->next = nex_cp->next;
            nex_cp ->next = pre->next;
            pre->next = nex_cp;
        }
        return dummy->next;
    }
};
