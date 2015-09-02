class Solution {
public:
    unordered_map<int, string> table={
    {0, ""}, {1, "One"},{2, "Two"},{3, "Three"},{4, "Four"},{5, "Five"},{6, "Six"},{7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"},{70,"Seventy"},{80, "Eighty"},{90, "Ninety"}
    };
    string threeDigits(int n){
        string res="";
        if(n>=100) {
            res += table[n/100] + " Hundred";
            n = n % 100;
        }
        if(res.length()>0 && n>0) res += " ";
        if(n<=20) res += table[n];
        else{
            int ones = n%10;
            int tens = n - ones;
            res += table[tens];
            if(ones > 0) res += " " + table[ones];
        }
        return res;
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string words = "";
        if(num / 1000000000 > 0){
            int b = num / 1000000000;
            words += threeDigits(b) + " Billion";
            num = num % 1000000000;
        }
        if(num/1000000 > 0){
            int m = num / 1000000;
            if(words.length()>0 && m > 0) words += " ";
            words += threeDigits(m) + " Million";
            num = num % 1000000;
        }
        if(num/1000 > 0){
            int t = num / 1000;
            if(words.length()>0 && t>0) words += " ";
            words += threeDigits(t) + " Thousand";
            num = num % 1000;
        }
        if(words.length() > 0 && num > 0) words += " ";
        words += threeDigits(num);
        return words;
    }
};
