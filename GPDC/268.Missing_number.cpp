class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, SIZE = nums.size();
        int actual_sum = (SIZE * (SIZE+1))/2;
        for(int& num : nums)sum+=num;
        return actual_sum-sum;
    }
};
