class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        if(intervals.size()<=1)return intervals.size();
        
        int result = 1; 
        int SIZE = intervals.size();
        
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>min_heap;
        min_heap.push(intervals[0][1]);
        
        for(int i=1;i<SIZE;i++){
            if(intervals[i][0]>=min_heap.top())min_heap.pop();
            min_heap.push(intervals[i][1]);
        }
        
        return min_heap.size(); 
    }
};
