class Solution {
public:
    string commonPrefix(string& a, string& b, int SIZE){
        string result = "";
        for(int i=0;i<SIZE;i++){
            if(a[i] != b[i])break;
            result = result + a[i];
        }
        return result;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];
        for(int i=1;i<strs.size();i++){
            int SIZE = min(result.size(),strs[i].size());
            result = commonPrefix(result,strs[i],SIZE);
            if(result.size() == 0)return result;
        }
        return result;
    }
};