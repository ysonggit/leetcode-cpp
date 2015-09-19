class Solution {
public:
    string say(string num){
        int i=0;
        string next;
        while(i<num.length()){
            int j=i+1;
            int count = 1;
            while(j<num.length() && num[j]==num[i]){
                j++;
                count++;
            }
            next.push_back((char)('0'+count));
            next.push_back(num[i]);
            i=j;
        }
        return next;
    }
    string countAndSay(int n) {
        if(n==0) return "";
        string res ="1";
        for(int i = 2; i<=n; i++){
            res = say(res);
        }
        return res;
    }
};
