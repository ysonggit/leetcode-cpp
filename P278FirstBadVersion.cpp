// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1) return isBadVersion(n) ? n : 0;
        int front = 1, back = n;
        while(front<back){
            //int mid = (front+back)/2; // mistake: front+back could cause overflow!
            int mid = front+(back-front)/2;
            if(isBadVersion(mid)){
                back = mid;
            }else {
                front = mid+1;
            }
        }
        return front;
    }
};
