class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);
        int M = nums1.size();
        int N = nums2.size();
        int low = 0, high = M;
        
        while(low<=high){
            int mid1 = low + (high-low)/2;
            int mid2 = (M+N+1)/2-mid1;
            
            int l1 = (mid1>0)?nums1[mid1-1]:INT_MIN;
            int l2 = (mid2>0)?nums2[mid2-1]:INT_MIN;
            
            int r1 = (mid1<M)?nums1[mid1]:INT_MAX;
            int r2 = (mid2<N)?nums2[mid2]:INT_MAX;
            
            //valid condition
            if(l1<=r2 && l2<=r1){
                if((M+N)%2!=0) return (double)max(l1,l2); 
                else return (max(l1,l2)+ min(r1,r2))/2.0;
            }
            else if(l1>r2) high = mid1-1; //reduce elements in the first half
            else low = mid1+1; //increase the elements in the first half 
        }
        return -1;
    }
};