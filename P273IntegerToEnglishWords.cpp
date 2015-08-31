class Solution {
public:
    // 破题！ 太他妈的无聊了！！
    string less_than_10[10] ={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    string less_than_20[10] ={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string less_than_100[10] ={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string units [4] ={"","Thousand","Million","Billion"}; // maximum is 2,147,483,647 
    
    string chunkToWords(int num, int greater_than_1000){
        if(num==0) return ""; 
        bool greater_than_100 = false;
        string prefix ="";
        if(num>99){
            greater_than_100 = true;
            prefix = less_than_10[num/100] + " Hundred";
            
        }
        num = num%100;
        if(num==0 && greater_than_100) return prefix;
        string two_digits = "";
        if(num>0 && num<=9){
            two_digits = less_than_10[num];
        }else if(num>=10 && num<20){
            two_digits = less_than_20[num%10]; // mistake: [num]
        }else{// >=20
            string tens = less_than_100[num/10];
            int digit = num%10;
            string ones = (digit==0) ? "" : (" " + less_than_10[digit]);
            two_digits = tens + ones;
        }
        return (greater_than_100) ? prefix + " " + two_digits : two_digits;
    }
    
    string numberToWords(int num) {
        if(num==0) return "Zero"; // corner case "0"
        // chunck into 3digits: each chunck has 3 digits
        stringstream ss;
        ss << num;
        string number_str = ss.str();
        int n = number_str.length();
        int num_chunks = (int) ceil(1.0*n/3);
        string words;
        for(int i = 1; i<=num_chunks; i++){
            int start_idx = n - i * 3;
            if(start_idx < 0) start_idx = 0;
            string chunck = number_str.substr(start_idx); 
            if(num==12345) cout<<chunck<<endl;
            int new_size = number_str.length() - chunck.size();
            if(new_size<0) new_size= 0;
            number_str = number_str.substr(0, new_size);
            string suffix = chunkToWords(stoi(chunck), i);
            if(i>1 && suffix.length()>0) suffix = suffix +" " + units[i-1] + " ";
            words = words.insert(0, suffix);
        }
        return (words[words.length()-1]==' ') ? words.substr(0, words.length()-1) : words;
    }
};
