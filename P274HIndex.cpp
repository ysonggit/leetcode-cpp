class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n==0) return 0;
        sort(citations.begin(), citations.end()); // mistake : must in increasing order
        int h_index = 0;
        for(int i=0; i<n; i++){
            h_index = max(h_index, min(citations[i], n-i));
        }
        return h_index;
    }
};
