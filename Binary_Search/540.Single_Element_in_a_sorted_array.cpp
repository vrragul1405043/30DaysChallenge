class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-2;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid%2){//odd index
                if(nums[mid] == nums[mid-1])low = mid+1;
                else high = mid-1;
            }
            else{//even index
                if(nums[mid] == nums[mid+1])low = mid+1;
                else high = mid-1;
            }
        }//end while
        return nums[low];
    }
};
