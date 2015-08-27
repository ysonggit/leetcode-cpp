class Solution {
public:
    /*
        1 2 3 2 4 0 1
        
                |
            |   |
          | | | | 
        | | | | |   |
        
     two pointers method, track the global max area
    */
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        int global_max_area = 0;
        int front = 0, back = n-1;
        while(front<back){
            int left_bar = height[front], right_bar = height[back];
            int cur_area = min(right_bar, left_bar) * (back-front);
            global_max_area = max(global_max_area, cur_area);
            if(left_bar < right_bar) front++;
            else back--;
        }
        return global_max_area;
    }
};
