// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if(n<2) return -1;
        int candidate=0;
        for(int i=1; i<n; i++){
            if(!knows(i, candidate)){
                candidate = i;
            }
        }
        for(int i=0; i<n; i++){
            if(i== candidate) continue;
            if(knows(candidate, i) || !knows(i, candidate)) return -1;
        }
        return candidate;
    }
};
