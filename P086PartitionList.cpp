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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return NULL;
        ListNode * dummyleft = new ListNode(-1);
        ListNode * dummyright = new ListNode(-2);
        ListNode * left = dummyleft;
        ListNode * right = dummyright;
        while(head != NULL){
            if(head->val < x){
                left->next = head;
                left = left->next;
            }else{
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }
        left->next = dummyright->next;
        right->next = NULL; // mistake: must set this one to avoid cyclic list
        return dummyleft->next;
    }
};
