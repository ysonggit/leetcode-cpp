class Solution {
public:
    // binary search
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n==0) return 0;
        int front = 0, back = n-1;
        while(front<=back){
            int mid = (front+back)/2;
            if(citations[mid] >= n-mid){ // mistake >= not >
                back = mid-1;
            }else{
                front = mid+1;
            }
        }
        return n-front;
    }
};
