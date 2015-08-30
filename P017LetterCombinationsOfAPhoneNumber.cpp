class Solution {
public:
    void dfs(vector<string> & res, string comb, int cur_idx, string & digits, unordered_map<unsigned int, string> & digit_letters){
        if(cur_idx == digits.size()){
            res.push_back(comb);
            return;
        }
        unsigned int key = (unsigned int) digits[cur_idx] - '0';
        string cand_letters = digit_letters[key];
        for(char c : cand_letters){
            comb = comb + c;
            int len = comb.length();
            dfs(res, comb, cur_idx+1, digits, digit_letters);
            comb = comb.substr(0, len-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        // create hashmap from letters to digits
        string letters_group[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        unsigned int numbers [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        unordered_map<unsigned int, string> digit_letters;
        for(int i=0; i<10; i++){
            digit_letters[numbers[i]] = letters_group[i];
        }
        vector<string> res;
        if(digits.length()==0) return res; // if given "", should return {} not {""}
        string comb="";
        dfs(res, comb, 0, digits, digit_letters);
        return res;
    }
};
