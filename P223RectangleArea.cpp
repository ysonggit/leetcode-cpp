class Solution {
public:
    // assume inputs are always valid representations of two rectangles
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = abs(D-B) * abs(C-A);
        int area2 = abs(H-F) * abs(G-E);
        if(B>=H || E>=C || F>=D || A>=G) return area1+area2;
        int width = abs(min(C,G)-max(A, E));
        int height = abs(min(H,D)-max(B,F));
        int intersection = width * height;
        return area1+area2-intersection;
    }
};
