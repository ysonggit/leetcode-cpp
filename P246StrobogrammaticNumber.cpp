class Solution {
public:
    unordered_map<char, char> table{
      {'0','0'},{'1','1'},{'6','9'}, {'9','6'}, {'8','8'}
    };
    bool isStrobogrammatic(string num) {
        int n = num.length();
        if(n==0) return true;
        int front = 0, back = n-1;
        while(front<=back){
            char _c = num[front], c_ = num[back];
            if(table.find(_c)==table.end() || table.find(c_)==table.end()) {
                return false;
            }
            if(front==back) return _c == table[_c];
            if(table[_c] != c_) return false;
            front++;
            back--;
        }
        return true;
    }
};
