class Solution {
public:
    // repeated digital sum: return 1+(num-1)%9
    int addDigits(int num) {
        if(num<10) return num;
        int sum = 0;
        int dividend = 1;
        while(num/dividend>9){
            dividend *=10;
        }
        while(num>0){
            int leftmost = num/dividend;
            num %= dividend;
            sum += leftmost;
            dividend /=10;
        }
        return addDigits(sum);
    }
};
