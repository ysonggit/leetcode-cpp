class Solution {
public:
    // 1. transpose image
    // 2. reverse each row
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        if(n<2) return;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
