/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return NULL;
        unordered_map<int, RandomListNode*> copied;
        RandomListNode * cur = head;
        while(cur != NULL){
            int val = cur->label;
            if(copied.find(val)== copied.end()){
                copied[val] = new RandomListNode(val);
            }
            if(cur->next != NULL){
                int nex_val = cur->next->label;
                if(copied.find(nex_val)== copied.end()){
                    copied[nex_val] = new RandomListNode(nex_val);
                }
                copied[val]->next = copied[nex_val];
            }
            if(cur->random != NULL){
                int rand_val = cur->random->label;
                if(copied.find(rand_val)==copied.end()){
                    copied[rand_val] = new RandomListNode(rand_val);
                }
                copied[val]->random = copied[rand_val];
            }
            cur = cur->next;
        }
        return copied[head->label];
    }
};
