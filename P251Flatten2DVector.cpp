class Vector2D {
public:
    int row, col;
    vector<vector<int> > mat;
    Vector2D(vector<vector<int>>& vec2d) {
        mat = vec2d;
        row = 0;
        col = 0;
    }

    int next() {
        return mat[row][col++];
    }

    bool hasNext() {
        if(mat.size()==0) return false;
        // check the ranges of row and col
        while(row<mat.size() && col>= mat[row].size()){
            row++;
            col = 0; // reset col
        }
        return row < mat.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
