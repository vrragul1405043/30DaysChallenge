class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        subsetsWithDupUtil(0, nums, ds, result);
        return result;
    }
private:
    void subsetsWithDupUtil(int id, vector<int>&nums, vector<int>&ds, vector<vector<int>>&result){
       result.push_back(ds);
       for(int i=id;i<nums.size();i++){
           if(i>id && nums[i]==nums[i-1])continue;
           ds.push_back(nums[i]);
           subsetsWithDupUtil(i+1,nums,ds,result);
           ds.pop_back();
       }    
    }
};