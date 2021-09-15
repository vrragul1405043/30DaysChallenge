class Solution {
public:
    string reverseWords(string s) {
        int start = 0, SIZE = s.size(), end = 0;
        string result="";
        while(start<SIZE){
            while(start<SIZE && s[start]==' ')++start;
            if(start>=SIZE)break;
            end = start+1;
            while(end<SIZE && s[end]!=' ')end++;
            if(result.size()==0)result = s.substr(start,end-start);
            else result = s.substr(start,end-start)+" "+result;
            start = end+1;
        }
        return result;
    }
    
};
