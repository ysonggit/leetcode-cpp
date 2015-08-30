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
    // classic two pointers solution
    // always, check nullptr
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return head;
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * fast = dummy;
        ListNode * slow = dummy;
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        while(fast->next!=nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        // delete slow->next
        ListNode * to_del = slow->next;
        slow->next = slow->next->next;
        delete to_del;
        to_del = nullptr;
        return dummy->next;
    }
};
