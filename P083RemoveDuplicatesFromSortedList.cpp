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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy->next;
        while(cur!=NULL && cur->next!=NULL){
            while(cur->val == cur->next->val){
                ListNode * dup = cur->next;
                cur->next = cur->next->next;
                delete dup;
                dup = NULL;
                if(cur->next==NULL) break;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
