class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>table;
        bool isOddCountPresent = false;
        int result = 0;
        for(char& c : s)table[c]++;
        for(auto it = table.begin(); it!=table.end(); ++it){
            if(it->second%2){
                isOddCountPresent = true;
                result+=(it->second-1);
            }
            else{
                result+=it->second;
            }
        }//end for
        
        result = (isOddCountPresent)?result+1:result;
        return result;   
    }
};
