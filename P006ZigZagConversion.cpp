class Solution {
public:
    /*
    From tju_xu's solution
    The distribution of the elements is period.

    P   A   H   N
    A P L S I I G
    Y   I   R
    
    For example, the following has 4 periods(cycles):
    
    P   | A   | H   | N
    A P | L S | I I | G
    Y   | I   | R   |
    
    The size of every period is defined as "cycle"
    
    cycle = (2*nRows - 2), except nRows == 1.
    In this example, (2*nRows - 2) = 4.
    
    In every period, every row has 2 elements, except the first row and the last row.
    
    Suppose the current row is i, the index of the first element is j:
    
    j = i + cycle*k, k = 0, 1, 2, ...
    The index of the second element is secondJ:
    
    secondJ = (j - i) + cycle - i
    (j-i) is the start of current period, (j-i) + cycle is the start of next period.
    */
    string convert(string s, int numRows) {
        int n = s.length();
        string res = "";
        if(n==0) return res;
        if(numRows == 1) return s; // mistake : special case!
        int cycle_size = 2 * numRows -2;
        for(int i=0; i<numRows; i++){
            for(int j = i; j<n; j += cycle_size){
                res = res + s[j];   // res = res + string(s[j]) does not compile
                int second_j = (j-i) + cycle_size - i;
                if(i>0 && i<numRows-1 && second_j < n){
                    res = res + s[second_j];
                }
            }
        }
        return res;
    }
};
