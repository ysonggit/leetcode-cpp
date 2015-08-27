class Solution {
public:
    string intToRoman(int num) {
        int numeric[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string letters[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int n = 13;
        string roman="";
        while(num>0){
            for(int i=0; i<n; i++){
                if(num>=numeric[i]){
                    num-= numeric[i];
                    roman = roman + letters[i];
                    break; // must restart comparing from numeric[0], for example 2000
                }
            }
        }
        return roman;
    }
};
