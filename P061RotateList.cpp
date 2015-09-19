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
    ListNode* rotateRight(ListNode* head, int k) {
        // assume no cycle exists in the list
        int n = 0;
        if(head==NULL) return head;
        if(head->next == NULL) return head;
        ListNode * dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode * cur = dummy;
        while(cur->next!=NULL){
            n++;
            cur = cur->next;
        }
        cur->next = dummy->next;
        // move cur forward by n-k steps
        k %= n;
        for(int i=0; i<n-k; i++){
            cur = cur->next;
        }
        // break list
        ListNode * newhead = cur->next;
        cur->next = NULL;
        return newhead;
        
    }
};
