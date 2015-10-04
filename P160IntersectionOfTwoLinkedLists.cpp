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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0, lenB=0;
        for(auto cur=headA; cur!=NULL; cur=cur->next) lenA++;
        for(auto cur=headB; cur!=NULL; cur=cur->next) lenB++;
        if(lenA>lenB) {
            for(int i=0; i<lenA-lenB; i++) headA = headA->next;
        }else{
            for(int i=0; i<lenB-lenA; i++) headB = headB->next;
        }
        while(headA !=NULL && headB!=NULL){
            if(headA==headB) return headA;
            headA= headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};
