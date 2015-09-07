    // cpp version of jeantimex's post
    vector<string> helper(int n, int m){
        // base case
        if(n==0) return vector<string>{""};
        if(n==1) return vector<string>{"0","1","8"};
        vector<string> less_by_2 = helper(n-2, m);
        vector<string> res;
        for(string inner : less_by_2){
            if(n!=m) res.push_back("0"+inner+"0"); // tricky
            res.push_back("1"+inner+"1");
            res.push_back("6"+inner+"9");
            res.push_back("8"+inner+"8");
            res.push_back("9"+inner+"6");
        }
        return res;
    }
    // n=3 [101,111,181,609,619,689,808,818,888,906,916,986]
    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);
    }
