class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>min_heap;
        for(int& number : nums){
            if(min_heap.empty() || min_heap.size()<k)min_heap.push(number);
            else{
                if(min_heap.top()>=number)continue;
                else{
                    min_heap.pop();
                    min_heap.push(number);
                }
            } 
        }
        return min_heap.top();
    }
};
