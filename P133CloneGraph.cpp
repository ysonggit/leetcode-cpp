/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;
        unordered_map<int, UndirectedGraphNode*> cloned;
        queue<UndirectedGraphNode*> Q;
        Q.push(node);
        cloned[node->label] = new UndirectedGraphNode(node->label);
        while(!Q.empty()){
            auto cur = Q.front();
            Q.pop();
            for(auto nb : cur->neighbors){
                if(cloned.find(nb->label)==cloned.end()){
                    cloned[nb->label] = new UndirectedGraphNode(nb->label);
                    Q.push(nb); // must be here
                }
                cloned[cur->label]->neighbors.push_back(cloned[nb->label]);
            }
        }
        return cloned[node->label];
    }
};
