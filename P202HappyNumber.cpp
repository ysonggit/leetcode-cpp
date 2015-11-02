class Solution {
public:
    unordered_map<int, bool> cache;
    bool isHappy(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        if(cache.find(n)!=cache.end()) return cache[n];
        long long sum = 0;
        for(char c : to_string(n)){
            sum += pow((int)(c-'0'), 2);
        }
        if(sum==1) {
            cache[n] = true;
            return true;
        }
        cache[n] = false;
        return isHappy(sum);
    }
};
