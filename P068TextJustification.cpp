class Solution {
public:
    // from xuewuxiao
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int cur = 0, n = words.size();
        while(cur<n){
            int last = cur, cur_line_width = words[cur++].size();
            while(cur<n && cur_line_width+1+words[cur].size()<= maxWidth){
                // greedily adding one more word to cur line
                cur_line_width += 1 + words[cur++].size();
            }
            int spaces = 1; //how many single spaces should have between every two words
            int extra = 0; // how many extra spaces should be appended to justify linewidth
            int num_words = cur-last; // how many words in current line
            if(cur<n && cur != last + 1){ // not the last word
                spaces = (maxWidth- cur_line_width)/(num_words-1)+1;
                extra = (maxWidth- cur_line_width)%(num_words-1);
            }
            res.push_back(words[last++]);
            while(extra--){
                res.back().append(spaces+1, ' ');
                res.back().append(words[last++]);
            }
            while(last < cur){
                res.back().append(spaces, ' ');
                res.back().append(words[last++]);
            }
            res.back().append(maxWidth-res.back().size(), ' ');
        }
        return res;
    }
};
