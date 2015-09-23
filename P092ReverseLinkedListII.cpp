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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL || m>n || m<0 || n<0) return head;
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * pre = dummy;
        for(int i=0; i<m-1; i++){
            pre = pre->next;
        }
        ListNode * cur = pre->next;
        for(int i=0; i<n-m; i++){
            ListNode * nex_cp = cur->next;
            cur->next = nex_cp->next;
            nex_cp->next = pre->next;
            pre->next = nex_cp;
        }
        return dummy->next;
    }
};
