#include <iostream>
#include<bits/stdc++.h>

using namespace std;


vector<int>compute_lps(string pattern){
    vector<int>lps(pattern.size(),0);
    int j = 0, i=1;
    while(i<pattern.size()){
        //char matches increment both the j and i
        if(pattern[i] == pattern[j]){
            lps[i] = j+1;
            i+=1;
            j+=1;
        }//end if
        else{
            if(j!=0){
                j = lps[j-1];//if it is midway we assign previous i to index
            }
            else{
                lps[i] = 0;// no match therefore put 0 and increment the pattern pointer (i)
                i++;
            }
        }//end else
    }//end for
    return lps;
}

bool isMatch(string text, string pattern, vector<int>&lps){
    int i = 0;//text_ptr
    int j = 0;//pattern pointer
    while (i<text.size() && j<pattern.size()){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }//end if
        else{
            if(j!=0){
                j=lps[j-1];
            }//end if
            else{
                i+=1;
            }//end else
        }//end else
    }//end for
    
    if(j == pattern.size())return true;
    return false;
}

int main()
{
    string pattern = "abcaby";
    string text = "abxabcabcaby";
    vector<int>lps = compute_lps(pattern);
    if(isMatch(text,pattern,lps))cout<<"There is a match "<<endl;
    else cout<<"There is not a match "<<endl;
    return 0;
}
