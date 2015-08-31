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
    // mark start node, end node of k nodes
    // remember pre->start and end-nex nodes
    // reverse every k nodes, and then rejoin to the list
    // pre--> cur -> nex --> tail
    ListNode* reverse(ListNode * head, ListNode * tail){
        ListNode * cur = head;
        ListNode * pre = NULL;
        while(cur != tail){
            ListNode * nexcp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nexcp;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode * dummy = new ListNode(-1);
        ListNode * cur = head;
        dummy->next = cur;
        ListNode * pre = dummy;
        int count = 0;
        ListNode * after;
        while(cur != NULL){
            count++;
            if(count%k==0){
                after = cur->next;  // important!
                pre->next = reverse(pre->next, cur->next);
                ListNode * rev_tail = pre->next;
                for(int i=0; i<k-1; i++){
                    rev_tail = rev_tail->next;
                }
                rev_tail->next = after;
                // move pre forward by jumping k steps
                pre = rev_tail;
                cur = pre->next;
            }else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
