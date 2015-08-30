class Codec {
public:
    // challenge: strs= {"", "", ""} return {"","",""} , not {} 
    //            strs={} return {}
    // Encodes a list of strings to a single string.
    // idea is from cityhuntermx 
    // use a 10-bit header to record the length of string
    // tip: using setfill and setw
    // http://www.cplusplus.com/reference/iomanip/setfill/
    string encode(vector<string>& strs) {
        string res;
        for(string s : strs){
            ostringstream oss;
            oss<<setfill('0')<<setw(10)<<s.length() << s;
            res = res + oss.str();
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        if(s.length()==0) return res;
        int i=0;
        while(i<s.length()){
            string header = s.substr(i, 10);
            stringstream ss;
            ss<< header;
            int str_len;
            ss>>str_len;
            res.push_back(s.substr(i+10, str_len));
            i += 10 + str_len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
