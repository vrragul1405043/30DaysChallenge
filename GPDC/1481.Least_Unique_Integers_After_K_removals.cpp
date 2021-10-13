class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        //comparator sorting based on the count
        auto comparator = [](pair<int,int>&a, pair<int,int>&b){
            return a.second<b.second;
        };
        
        //min_heap to store only the counts as we don't care what element is present
        priority_queue<int,vector<int>,greater<int>>min_heap;
        
        //to store the frequency
        unordered_map<int,int>counts;
        
        //storing the frequency in the map
        for(int& num : arr) counts[num]++;
        
        //transferring from map to min_heap
        for(auto& count : counts) min_heap.push({count.second});
        
        
        //reducing the count from heap if 0 we remove/pop it out and at the end return the size
        while(min_heap.size()>0 && k>0){
            if(min_heap.top()>k){
                break;
            }
            else{
                k-=min_heap.top();
                min_heap.pop();
            }
        } 
        return min_heap.size();  
    }
};
