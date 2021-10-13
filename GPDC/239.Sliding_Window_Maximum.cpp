class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int SIZE = nums.size();
        deque<int>Q;
        vector<int>result;
        int windowStart = 0;//sliding window start
        
        //iterating windowEnd
        for(int windowEnd=0;windowEnd<SIZE;windowEnd++){
            if(Q.empty())Q.push_back(windowEnd);//if Q empty push the index into the queue
            else{
                
                //if the decreasing order is not maintained we will pop front
                while(!Q.empty() && nums[windowEnd]>nums[Q.back()])Q.pop_back();
                
                
                Q.push_back(windowEnd); // Q push windowEnd
            }
            
            //if sliding window width is reached
            if(windowEnd-windowStart+1>=k){
                result.push_back(nums[Q.front()]);
                
                //pop if the index is outdated
                while(!Q.empty() && Q.front()<=windowStart) Q.pop_front();
                
                //increment windowStart
                windowStart++;
            } 
        }//end for
        return result;
    }
};
