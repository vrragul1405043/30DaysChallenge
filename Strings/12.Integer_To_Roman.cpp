class Solution {
public:
    string intToRoman(int num) {
        vector<string>roman{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int>integers{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int SIZE = roman.size();
        string result = "";
        for(int i=0;i<SIZE;i++){
            while(num>=integers[i]){
                num-=integers[i];
                result+=roman[i];
            }
        }//end for
        return result;
    }
};
