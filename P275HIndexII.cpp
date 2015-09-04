class Solution {
public:
    // binary search
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n==0) return 0;
        int h_idx = 0;
        /**
         * naive O(n) solution
            for(int i=0; i<n; i++){
                h_idx = max(h_idx, min(citations[i], n-i));
            }
         */
        int front = 0, back = n-1;
        while(front<=back){
            int mid = (front+back)/2;
            int cur_cites = citations[mid]; 
            if(cur_cites == n-mid){
                return cur_cites;
            }else if(cur_cites > n-mid){
                h_idx = n-mid;
                --back;
            }else{
                h_idx = cur_cites;
                ++front;
            }
        }
        return h_idx;
    }
};
