class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>result;
        util(0,nums,result,ds,nums.size());
        return result;
    }
private:
    void util(int id, vector<int>&nums, vector<vector<int>>&result, vector<int>&ds, int N){
        if(id==N){
            result.push_back(ds);
            return;
        }  
        ds.push_back(nums[id]);
        util(id+1,nums,result,ds,N);//pick
        ds.pop_back();//backtracking
        util(id+1,nums,result,ds,N);//not pick
    }
};