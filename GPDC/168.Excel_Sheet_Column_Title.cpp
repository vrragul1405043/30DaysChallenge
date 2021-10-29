class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while(columnNumber>0){
            columnNumber-=1;//because adding with A should be less than 1 because A + 1 = B
            result = char('A'+ (columnNumber%26)) + result;
            columnNumber/=26;
        }
        return result;
    }
};
