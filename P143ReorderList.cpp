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
    void reorderList(ListNode* head) {
        if(head==NULL) return;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL; // break list into two pieces
        // reverse right half
        ListNode* pre = NULL;
        ListNode* nex_cp = NULL;
        while(fast!=NULL){
            nex_cp = fast->next;
            fast->next = pre;
            pre = fast;
            fast = nex_cp;
        }
        ListNode* cur = dummy;
        ListNode* first = head;
        ListNode* second = pre;
        // like partition list
        bool add_first = true;
        while(first!=NULL && second!=NULL){
            if(add_first){
                cur->next = first;
                first = first->next;
            }else{
                cur->next = second;
                second = second->next; 
            }
            cur = cur->next;
            add_first = add_first ? false : true;
        }
        cur->next = (first!=NULL) ? first : second;
        head = dummy->next;
    }
};
