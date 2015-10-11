class Solution {
public:
    vector<int> nextRow(vector<int> cur){
        if(cur.size()==0) return vector<int>{1};
        if(cur.size()==1) return vector<int>{1,1};
        int n = cur.size()+1;
        vector<int> next(n, 1);
        for(int i=1; i<n-1; i++){
            next[i] = cur[i-1]+cur[i];
        }
        return next;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        vector<int> row;
        for(int i=1; i<=numRows; i++){
            row = nextRow(row);
            res.push_back(row);
        }
        return res;
    }
};
