class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> result; 
        sort(intervals.begin(), intervals.end());
        
        result.push_back(intervals[0]);
        int resultIndex = 0;
        
        for (int i=1; i<intervals.size(); i++){
            if (intervals[i][0] <= result[resultIndex][1]){
                result[resultIndex][1] = max(intervals[i][1], result[resultIndex][1]);
            } else {
                result.push_back(intervals[i]);
                resultIndex++;
            }
        }
        return result;
    }
};