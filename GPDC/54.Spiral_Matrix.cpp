class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;
        int direction = 0;
        vector<int>result;
        while(top<=bottom && left<=right){
            switch(direction){
                case 0:
                    //go right
                    for(int c=left;c<=right;c++)result.push_back(matrix[top][c]);
                    top++;
                    break;
                case 1:
                    //go down
                    for(int c=top;c<=bottom;c++)result.push_back(matrix[c][right]);
                    right--;
                    break;
                case 2:
                    //go left
                    for(int c = right; c>=left; c--)
                        result.push_back(matrix[bottom][c]);
                    bottom--;
                    break;
                case 3:
                    //go up
                    for(int c=bottom;c>=top;c--)
                        result.push_back(matrix[c][left]);
                    left++;
                    break; 
            }
            direction = (direction+1)%4;   
        }
        return result; 
    }
};
