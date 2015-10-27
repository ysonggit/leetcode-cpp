class Solution1 {
public:
    // Binary search and high is always converged to the one that 1 larger than the result.
    // return high-1
    int mySqrt(int x) {
        if(x<2) return x;
        int low = 0, high = x;
        while(low<high){
            int mid = low+(high-low)/2;
            if(x/mid>=mid) low= mid+1;
            else high = mid;
        }
        return high-1;
    }
};

public class Solution2 {
    public int mySqrt(int x) {
        if(x<2) return x;
        int low = 0, high = x;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(x/mid >= mid && x/(mid+1) < mid+1){
                return mid;
            }else if(x/mid < mid){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
}
