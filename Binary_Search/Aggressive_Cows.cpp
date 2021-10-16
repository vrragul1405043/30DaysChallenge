/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;


bool isPossible(vector<int>&positions, int minDist, int cows){
    int lastPlacedCow = positions[0];
    cows-=1;
    for(int i=1;i<positions.size();i++){
        if(positions[i]-lastPlacedCow>=minDist){
            lastPlacedCow = positions[i];
            cows-=1;
        }
        else continue;
    }
    
    return cows==0;
}

int main()
{
    vector<int>positions = {1,2,4,8,9};
    int SIZE = positions.size();
    
    int low = positions[1] - positions[0];
    int high = positions[SIZE-1] - positions[0];
    
    int cows = 3;
    
    int result = INT_MAX;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isPossible(positions,mid,cows)){
            result = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    
    cout<<"Maximal minimum distance between the cows are :: "<<result<<endl;
    return 0;
}

