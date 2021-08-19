class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local_max = 0, global_max = INT_MIN;
        for(int num : nums){
            local_max = max(local_max+num, num);
            global_max = max(global_max,local_max);
        }
        return global_max;
    }
};