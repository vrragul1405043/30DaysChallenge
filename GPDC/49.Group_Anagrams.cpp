class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<string,vector<string>>table;
        
        for(string& str : strs){
            string temp = str;
            sort(str.begin(),str.end());
            table[str].push_back(temp);
        }
        
        for(auto it = table.begin(); it!=table.end(); ++it)
            result.push_back(it->second);
        
        return result;
    }
};
