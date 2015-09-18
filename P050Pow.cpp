class Solution {
public:
    // divide and conquer
    // x^n = x^(n/2) * x^(n/2) * x^(n%2)
    bool doubleEqual(double a, double b){
        return abs(a-b) <= std::numeric_limits<double>::epsilon();
    }
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(n==1) return x;
        if(doubleEqual(x, 1.0)) return 1.0;
        if(doubleEqual(x, -1.0)) return (n%2==0) ? 1.0 : -1.0;
        if(n<0) return 1.0/myPow(x, -n);
        double temp = myPow(x, n/2);
        temp *= temp;
        if(n%2==1) temp *= x;
        return temp;
    }
};
