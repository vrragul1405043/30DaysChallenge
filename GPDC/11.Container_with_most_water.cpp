class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1, result = 0;
        while(start<end){
            result = max(result, (end-start)*min(height[start],height[end]));
            if(height[end]<height[start])end--;
            else start++;
        }
        return result;
    }
};
