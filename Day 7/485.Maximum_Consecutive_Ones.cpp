class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current = 0, SIZE = nums.size(),result = 0;
        for(int i=0;i<SIZE;i++){
            if(nums[i]==1)current++;
            else current = 0;
            result = max(result,current);
        }
        return result;
    }
};
