class Solution {
public:
    int lengthOfLastWord(string s) {
        int ptr = s.size()-1, result = 0;
        while(ptr>=0 && s[ptr] == ' ')ptr--;
        while(ptr>=0 && s[ptr]!=' '){
            result+=1;
            ptr-=1;
        }
        return result;
    }
};
