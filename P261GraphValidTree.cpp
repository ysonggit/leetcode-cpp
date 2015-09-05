class Solution {
public:
    // union-find algorithm / disjoint set
    //http://www.cs.cornell.edu/~wdtseng/icpc/notes/graph_part4.pdf
    vector<int> uf; // uf[i] = j means the root of i is j
    int find(int x){
        // slow finding
        //if(uf[x] == x) return x;
        //return find(uf[x]);
        // fast finding with path compression
        /**
         Suppose that we call FIND(x), and it returns z, the leader of x's party. 
         What we could do is reset uf[x] to z,
         so that next time when we call FIND(x),it would return in just 2 iterations. 
         */
        if(uf[x]!= uf[uf[x]]) uf[x] = find(uf[x]);
        return uf[x];
    }
    void unionNodes(int x, int y){
        uf[find(x)] = find(y);
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(edges.size()==0) return n<=1; // mistake: 1 [] is valid tree
        uf.resize(n);
        for(int i=0; i<n; i++){
            uf[i] = i;
        }
        for(auto e : edges){
            auto child = e.first;
            auto parent = e.second;
            auto root1 = find(child);
            auto root2 = find(parent);
            if(root1 == root2) return false;
            unionNodes(child, parent);
        }
        return edges.size()==n-1;
        
    }
};
