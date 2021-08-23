class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int SIZE = nums.size();
        int i,j;
        for(i=SIZE-2;i>=0;i--){
            if(nums[i]<nums[i+1])break;
        }
        
        if(i>=0){
            for(j=SIZE-1;j>i;j--){
                if(nums[i]<nums[j])break;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};