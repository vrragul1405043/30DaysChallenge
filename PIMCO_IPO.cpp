#include<iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> getUnallottedUsers_Ragul(vector<vector<int>> bids, int totalShares) {
    int SIZE = bids.size(), i=0;
    int j = 0;
    vector<int>result;
    map<int,vector<pair<int,int>>>table;
    sort(bids.begin(),bids.end(),[](vector<int>&a, vector<int>&b){
        if(a[2]>b[2])return true;
        else{
            if(a[2] == b[2]){
                if(a[3]<b[3]) return true;
            }
            return false;
        } 
    });
    
    for(int i=0;i<SIZE;i++){
        table[bids[i][2]].push_back({bids[i][0],bids[i][1]});
        result.push_back(bids[i][0]);
    }
    
    for(auto it = table.rbegin(); it!=table.rend(); it++){
        vector<pair<int,int>>temp = it->second;
        if(temp.size()==1){
            int shares = temp[0].second;
            totalShares-=shares;
            auto itr = find(result.begin(), result.end(), temp[0].first);
            result.erase(itr);
            if (totalShares <= 0) break;
        }//end size i
        else{
                int rem_shares = 0;
                for(int idx = 0; idx<temp.size(); idx++){              
                    temp[idx].second-=1;
                    totalShares-=1;
                    rem_shares+=temp[idx].second;
                    auto itr = find(result.begin(), result.end(), temp[idx].first);
                    if(itr != result.end()) result.erase(itr);
                    if (totalShares <= 0)break;
                }//end for
                totalShares-=rem_shares;
                if (totalShares<=0) break;
        }//end else    
    }//end for
    sort(result.begin(), result.end());
    return result;
}

vector<int> getUnallottedUsers_Aravind(vector<vector<int>> bids, int totalShares) {

    int SIZE = bids.size();
    set<int> userSet;
    map<int, vector<pair<int, int>>> priceMap;

    // Comparator
    auto comparator = [](vector<int>& A, vector<int>& B){
        return A[2]>B[2] || (A[2]==B[2] && A[3]<B[3]);
    };

    // Sort the Array
    sort(bids.begin(), bids.end(), comparator);

    // Store in a map.
    for (int i=0; i<SIZE; i++){
        priceMap[bids[i][2]].push_back(make_pair(bids[i][0], bids[i][1]));
        userSet.insert(bids[i][0]);
    }

    // Iterate and remove users from the set one by one.
    for (auto it=priceMap.rbegin(); it!=priceMap.rend(); it++){
        auto tieArray = it->second;
        if (tieArray.size()==1){
            totalShares -= tieArray[0].second;
            userSet.erase(tieArray[0].first);
            if (totalShares <=0) break;
        } 
         else {
            int remshares = 0;
            for (int i=0; i<tieArray.size(); i++){
                totalShares--;
                tieArray[i].second--;
                remshares += tieArray[i].second;
            if (userSet.find(tieArray[i].first) != userSet.end()) userSet.erase(tieArray[i].first);
            if (totalShares==0) return { userSet.begin(), userSet.end() };
        }//end for
            totalShares -= remshares;
            if (totalShares <= 0) break;
        }//end else
    }//end for map
    return { userSet.begin(), userSet.end() };
}

int main(){
    //<user_id, no_of_shares, price, timestamp>
    vector<vector<int>>bids = {{1,5,5,0},{2,7,8,1},{3,7,5,1},{4,10,3,3}};
    int totalShares = 18;

    vector<int>result = getUnallottedUsers_Ragul(bids,totalShares);
    vector<int>result1 = getUnallottedUsers_Aravind(bids,totalShares);
    for(int& num : result)cout<<num<<" "<<endl;
    for(int& num : result1)cout<<num<<" "<<endl;
    
    return 0;
}
