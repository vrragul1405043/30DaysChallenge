
class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int SIZE = str.size();
        string temp = str[0];
        for(int i=1;i<SIZE;i++){
            temp = commonUtil(str[i],temp);
            if(!temp.size())return "";
        }
        return temp;
    }
private:
    string commonUtil(string s1, string s2){
        int i=0, j=0, SIZE_1 = s1.size(), SIZE_2 = s2.size();
        string res = "";
        while(i<SIZE_1 && j<SIZE_2){
            if(s1[i++]==s2[j++]){
                res+=s1[i-1];
            }
            else break;
        }
        return res;
    }
};
