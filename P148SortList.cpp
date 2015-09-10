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
    ListNode * split(ListNode * head){
        if(head == NULL) return NULL;
        ListNode * dummy = new ListNode(-1);
        dummy->next = head; // make sure to use dummy 
        ListNode * fast = dummy;
        ListNode * slow = dummy;
        while(fast!=NULL && fast->next != NULL){
            fast= fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL; // break list
        return fast;
    }
    ListNode * merge(ListNode * l1, ListNode * l2){
        if(l1==NULL && l2==NULL) return NULL;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode * dummy = new ListNode(-1);
        ListNode * cur = dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head ==NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode * left = head;
        ListNode * right = split(head);
        return merge(sortList(left), sortList(right));
    }
};
