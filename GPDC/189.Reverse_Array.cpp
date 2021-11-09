class Solution {
public:
    
    void custom_reverse(vector<int>&nums, int start, int end){
        while(start<=end) swap(nums[start++],nums[end--]);
    }
    
    void rotate(vector<int>& nums, int k) {
        int SIZE = nums.size();
        k = k % SIZE;
        int split_ptr = SIZE-1;
        for(int i=0;i<k;i++) split_ptr--;
        custom_reverse(nums,split_ptr+1,SIZE-1);
        custom_reverse(nums,0,split_ptr);
        reverse(nums.begin(),nums.end());
    }
};
