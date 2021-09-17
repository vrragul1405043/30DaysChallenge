class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0, ptr = 1, SIZE = nums.size();
        if(SIZE<=1)return SIZE;
        for(int i=1;i<SIZE;i++){
            if(nums[start] == nums[i])continue;
            else{
                start++;
                nums[start]=nums[i];
            }
        }
        return start+1;
    }
};

