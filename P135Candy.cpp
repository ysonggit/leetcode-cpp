class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n<2) return n;
        // left[i] = j means i-th kid gets j candies 
        // in terms of his/her left neighbor
        vector<int> left(n,1), right(n,1);
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        for(int j=n-2; j>=0; j--){
            if(ratings[j]>ratings[j+1]){
                right[j] = right[j+1]+1;
            }
        }
        int total = 0;
        for(int i=0; i<n; i++){
            total += max(left[i], right[i]);
        }
        return total;
    }
};
