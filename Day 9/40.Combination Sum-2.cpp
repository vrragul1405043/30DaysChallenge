class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        vector<vector<int>>result;
        c2Util(candidates,ds,result,0,target);
        return result;
    }
    
    void c2Util(vector<int>&candidates, vector<int>&ds, vector<vector<int>>&result, int ind, int target){
        
        if(target == 0){
            result.push_back(ds);
            return;
        }
        
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i] == candidates[i-1])continue;
            if(candidates[i]>target)break;
            ds.push_back(candidates[i]);
            c2Util(candidates, ds, result, i+1, target-candidates[i]);
            ds.pop_back();//backtrack            
        }

    }
};