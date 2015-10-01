class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(n==0) return -1;
        //if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;
        // just one-pass
        int rest_sofar = 0, start = 0, accum = 0;
        for(int i=0; i<n; i++){
            int rest = rest_sofar + gas[i] - cost[i];
            accum += gas[i]-cost[i];
            if(rest < 0){
                start = i+1;
                rest_sofar = 0;
            }else{
                rest_sofar = rest;
            }
        }
        return accum < 0 ? -1 : start;
    }
};
