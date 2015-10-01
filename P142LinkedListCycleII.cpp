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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        bool cyclic = false;
        while(fast!=NULL&& fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                cyclic = true;
                break;
            }
        }
        if(!cyclic) return NULL;
        fast = head; // reset to head    
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
            if(fast==slow) break;
        }
        return slow;
    }
};
