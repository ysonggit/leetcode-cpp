class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        if(n==0) return 0;
        int idx1 = -1, idx2 = -1;
        int min_dist = n;
        for(int i=0; i<n; i++){
            string wd = words[i];
            if(wd==word1){
                idx1 = i;
            }
            if(wd==word2){
                idx2 = i;
            }
            if(idx1>=0 && idx2>=0) min_dist = min(min_dist, abs(idx2-idx1));
        }
        return min_dist;
    }
};
