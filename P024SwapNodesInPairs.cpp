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
    // pre -> cur -> nex -> nexnex
    //    |
    // pre -> nex -> cur -> nexnex
    ListNode * swapNodes(ListNode * pre, ListNode * cur){
        ListNode *nexnex = cur->next->next;
        pre->next = cur->next;
        cur->next = nexnex;
        pre->next->next = cur;
        return cur;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)  return head;
        if(head->next == NULL) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = dummy->next;
        while(cur!= NULL && cur->next != NULL){
            ListNode * nexnex = cur->next->next;
            pre = swapNodes(pre, cur);
            cur = nexnex;
        }
        return dummy->next;
    }
};
