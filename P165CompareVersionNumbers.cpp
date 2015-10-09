class Solution {
public:
    // from lchen77, take advantage of stringstream 
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1+"."), ss2(version2+".");
        int val1=0, val2 =0;
        char dot;  // type must be char 
        while(ss1.good()||ss2.good()){
            // >> extracts from front 
            if(ss1.good()) ss1>>val1 >> dot;
            if(ss2.good()) ss2>>val2 >> dot;
            if(val1>val2) return 1;
            else if(val1<val2) return -1;
            else{
                // mistake: must reset val1 and val2, otherwise, if ss1/ss2 is not good, 
                // val1/val2 keeps on using previous value
                val1 = val2 = 0;
            }
        }
        return 0;
    }
};
