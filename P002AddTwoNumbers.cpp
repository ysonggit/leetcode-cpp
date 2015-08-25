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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return nullptr;
        if(!l1) return l2;
        if(!l2) return l1;
        int carry = 0;
        ListNode * dummy = new ListNode(-1);
        ListNode * cur = dummy;
        while(l1!=nullptr || l2!=nullptr){
            int a = (!l1) ? 0: l1->val;
            int b = (!l2) ? 0: l2->val;
            int sum = (a + b + carry);
            int bit = sum%10;
            cur->next = new ListNode(bit);
            carry = sum/10;
            if(l1!=nullptr) l1 = l1->next;
            if(l2!=nullptr) l2 = l2->next;
            cur = cur->next;
        }
        if(carry>0) cur->next = new ListNode(carry);
        return dummy->next;
    }
};
