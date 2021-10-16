#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int>&pages, int threshold, int students){
    int requiredStudents = 1;
    int current_pages = 0;
    for(int i=0;i<pages.size();i++){
        if(current_pages + pages[i] <=threshold){
            current_pages+=pages[i];
        }
        else{
            current_pages = pages[i];
            requiredStudents++;
        }
    }//end for
    return requiredStudents<=students;
}



int main()
{
    int students = 2;
    vector<int>pages = {12,34,67,90};
    int S = 0, SIZE=pages.size();
    for(int i=0;i<SIZE;i++)S+=pages[i];
    int low = pages[0];
    int high = S;
    int ans = 0;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isPossible(pages,mid,students)){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<"The minimum number of pages is :: "<<ans<<endl;
    return 0;
}

