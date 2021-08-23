class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int SIZE = nums.size();
        int max_profit = INT_MIN;
        int min_element = INT_MAX;
        
        for(int i=0;i<SIZE;i++){
            min_element = min(min_element, nums[i]);
            max_profit = max(nums[i]-min_element, max_profit);
        }
        return max_profit;
    }
};