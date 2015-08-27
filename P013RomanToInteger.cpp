class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        if(n==0) return 0;
        int numeric[] = {1, 5, 10, 50, 100, 500, 1000};
        char alpha[] ={'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        unordered_map<char, int> map;
        for(int i=0; i<7; i++){
            map[alpha[i]] = numeric[i];
        }
        int num=0;
        for(int i=0; i<n; i++){
            char cur = s[i];
            if(i>0 && map[cur] > map[s[i-1]]){ // stupid mistake : cur > s[i-1]
                num += map[cur] - 2* map[s[i-1]];
            }else{
                num += map[cur];
            }
        }
        return num;
    }
};
