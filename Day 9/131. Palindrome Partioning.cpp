class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>ds;
        partitionUtil(s,result,ds,0);
        return result;
    }
private:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end])return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }
    
    void partitionUtil(string s, vector<vector<string>>&result, vector<string>&ds, int ind){
        if(ind == s.size()){
            result.push_back(ds);
            return;
        }//end if
        
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                ds.push_back(s.substr(ind,i-ind+1));
                partitionUtil(s,result,ds,i+1);
                ds.pop_back();
            }
        }//end for
    }
};