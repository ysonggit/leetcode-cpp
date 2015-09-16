class Solution {
public:
    void dfs(vector<string> & res, string s, string sol, vector<int> visited){
        if(sol.size()==s.size()){
            res.push_back(sol);
            return;
        }
        for(int i=0; i<s.size(); i++){
            if(i>0 && s[i]==s[i-1] && visited[i-1]) continue;
            if(visited[i]) continue;
            visited[i] = 1;
            sol.push_back(s[i]);
            dfs(res, s, sol, visited);
            visited[i] = 0;
            sol.pop_back();
        }
    }
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        int n = s.length();
        vector<int> freq(256, 0);
        for(char c : s){
            freq[(int)c]++;
        }
        int count_of_odd_occurance = 0;
        string half_s;
        string odd_char;
        for(int i=0; i<freq.size(); i++){
            int count= freq[i];
            char c = (char)i;
            if(count %2==1) {
                count_of_odd_occurance++;
                odd_char.push_back(c);
                // be careful : aaabb
                if(count>2){
                    for(int j=0; j< (count-1)/2; j++){
                        half_s.push_back(c);
                    }
                }
            }else{
                for(int j=0; j< count/2; j++){
                    half_s.push_back(c);
                }
            }
        }
        // no palindrome could be formed, return []
        if(count_of_odd_occurance > 1) return res;
        string sol;
        // generate half of palindrome without odd occurance
        vector<int> visited(half_s.size(), 0);
        dfs(res, half_s, sol, visited);
        for(string & pal : res){
            string rev = pal;
            reverse(rev.begin(), rev.end());
            pal += rev;
        }
        if(count_of_odd_occurance>0){
            for(string & pal : res){
                pal.insert(pal.size()/2, odd_char);
            }   
        }
        return res;
    }
};
