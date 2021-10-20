#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int compute_kth_element(vector<int>&a, vector<int>&b, int K){
    
    if(a.size()>b.size())return compute_kth_element(b,a,K);
    
    int M = a.size();
    int N = b.size();
    
    int low = 0;
    int high = M;
    
    //if the second array size is smaller than K then we have to pick atleast one element from the 1st array
    if(K>N)low = K-N;
    
    //if high is greater than K we need to update high to K
    if(high>K)high = K;
    
    while(low<=high){
        int mid1 = low + (high-low)/2;
        int mid2 = K-mid1;
        
        int l1 = (mid1>0)?a[mid1-1]:INT_MIN;
        int l2 = (mid2>0)?b[mid2-1]:INT_MIN;
        
        int r1 = (mid1<M)?a[mid1]:INT_MAX;
        int r2 = (mid2<N)?b[mid2]:INT_MAX;
        
        if(l1<=r2 && l2<=r1)return max(l1,l2);
        
        else if(l1>r2)high = mid1-1;
        else low = mid1+1;
    }
    return -1;
}

int main()
{
    vector<int>a = {7,12,14,15};
    vector<int>b = {1,2,3,4,9,11};
    int k= 6;
    cout<<"The kth element is :: "<<compute_kth_element(a,b,k);
    return 0;
}

