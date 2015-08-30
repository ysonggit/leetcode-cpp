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
    struct NodeCmp{
        bool operator()(ListNode * a, ListNode *b){
            return a->val > b->val; // for minheap
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, NodeCmp> minheap;
        ListNode * dummy = new ListNode(-1);
        ListNode * cur = dummy;
        for(int i=0; i<k; i++){
            ListNode * head = lists[i];
            if(head== nullptr) continue; // mistake: ALWAYS remember to check nullptr
            if(minheap.empty() || minheap.size()<k){
                minheap.push(head);
            }
            lists[i] = head->next;
        }
        ListNode * substitute = nullptr;
        while(!minheap.empty()){
            // pop top then insert another one
            substitute = minheap.top()->next;
            cur->next = minheap.top();
            cur= cur->next;
            minheap.pop();
            if(substitute != nullptr) minheap.push(substitute);
        }
        return dummy->next;
    }
};
