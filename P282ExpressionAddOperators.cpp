class Solution {
public:
    /* from  czonzhu  */
    void dfs(vector<string> & res, string sol, string num, 
            int target, int pos, long eval, long mult){
        if(pos==num.length()){
            if(eval == (long) target){
                res.push_back(sol);
                return;
            }
        }
        for(int i=pos; i<num.length(); i++){
            string m = num.substr(pos, i+1-pos);
            if(m.length()>1 && m[0]=='0') break; // tip: break not continue. 1000009
            //cout<<"sol="<<sol<<" eval= "<<eval<<" mult= "<<mult<<" m = "<<m<<endl;
            long cur = stol(m);
            if(pos==0){
                // the first number does not apply any operator
                dfs(res, sol+m, num, target, i+1, cur, cur);
            }else{
                // apply each binary arithmetic operator
                dfs(res, sol+"+"+m, num, target, i+1, eval+cur, cur);
                dfs(res, sol+"-"+m, num, target, i+1, eval-cur, -cur);
                // 1+2*3
                dfs(res, sol+"*"+m, num, target, i+1, eval-mult+mult*cur, mult* cur);
            }
        }
        
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if(num.length()==0) return res;
        string sol;
        dfs(res, sol, num, target, 0, 0, 0);
        return res;
    }
};
