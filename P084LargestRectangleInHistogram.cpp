class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if(height.empty()) return 0;
        height.push_back(0);
        int n = height.size();
        int max_area = 0;
        stack<int> highest_bars_left;
        for(int i=0; i<n; i++){
            while(!highest_bars_left.empty() &&
                    height[i] < height[highest_bars_left.top()]){
                int highest_idx = highest_bars_left.top();
                highest_bars_left.pop();
                int width = highest_bars_left.empty() ? i : (i-highest_bars_left.top()-1);
                max_area = max(max_area, width* height[highest_idx]);
            }
            highest_bars_left.push(i);
        }
        return max_area;
    }
};
