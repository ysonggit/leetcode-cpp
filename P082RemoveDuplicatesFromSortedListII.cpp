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
        ListNode* pre = dummy;
        bool dup_found = false;
        while(cur!=NULL && cur->next!=NULL){
            while(cur->val == cur->next->val){
                ListNode * dup = cur->next;
                cur->next = cur->next->next;
                delete dup;
                dup = NULL;
                dup_found = true;
                if(cur->next==NULL) break;
            }
            if(dup_found){
               pre->next = cur->next;
               cur = pre->next; 
               dup_found = false;
            }else{
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
