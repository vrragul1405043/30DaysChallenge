#include <iostream>
#include<bits/stdc++.h>

using namespace std;

//assuming high = 15 typically it will be large
// m*n is odd (given)

int count_values(vector<vector<int>>&nums, int target){
    int result = 0;
    for(int i=0;i<nums.size();i++){
        int low = 0, high = nums[i].size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[i][mid] <= target)low = mid+1;
            else high = mid-1;
        }
        result+=low;
    }
    return result;
}


int compute_median(vector<vector<int>>&nums){
    int low = 1, high = 15, rows = nums.size(), cols = nums[0].size();
    while(low<=high){
        int mid = low + (high-low)/2;
        int count = count_values(nums,mid);
        if(count>(rows * cols)/2)high = mid-1;
        else low = mid+1;
    }
    return low;
}

int main()
{
    vector<vector<int>>nums = {{1,3,6},{2,6,9},{3,6,9}};
    cout<<"The median of the matrix is :: "<<compute_median(nums)<<endl;
    return 0;
}

