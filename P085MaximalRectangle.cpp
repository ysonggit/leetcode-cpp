class Solution {
public:
    // convert to 1d array (histogram) and find largest rectange in histogram
    int largestRectangleArea(vector<int> & height){
        if(height.empty()) return 0;
        height.push_back(0);
        stack<int> highest_bars_left;
        int max_area = 0;
        for(int i=0; i<height.size(); i++){
            while(!highest_bars_left.empty() && 
                height[i] <= height[highest_bars_left.top()]){
                int highest_idx = highest_bars_left.top();
                highest_bars_left.pop();
                int width = highest_bars_left.empty() ? i : (i-highest_bars_left.top()-1);
                max_area = max(max_area, width * height[highest_idx]);
            }
            highest_bars_left.push(i);
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        vector<vector<int> > heights(m, vector<int>(n, 0));
        for(int j=0; j<n; j++) {
            heights[m-1][j] = (matrix[m-1][j]=='1') ? 1 : 0;
        }
        int max_rect = largestRectangleArea(heights[m-1]);
        for(int i=m-2; i>=0; i--){
            for(int j=0; j<n; j++){
                //strictly, should check overflow 
                heights[i][j]= (matrix[i][j]=='1') ? heights[i+1][j]+1 : 0;
            }   
            max_rect = max(max_rect, largestRectangleArea(heights[i]));
        }
        return max_rect;
    }
};
