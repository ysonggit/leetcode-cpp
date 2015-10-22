class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        vector<int> x, y;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        int n = x.size();
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int median_idx = (n&1) ? n/2 : n/2-1;
        int pos_x = x[median_idx], pos_y = y[median_idx];
        int total_dist = 0;
        for(int i=0; i<n; i++){
            total_dist += abs(x[i]-pos_x) + abs(y[i]-pos_y);
        }
        return total_dist;
    }
};
