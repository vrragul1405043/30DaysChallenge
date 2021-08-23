class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       
        int R = matrix.size();
        int C = matrix[0].size();
        bool isFirstRow = false;
        bool isFirstColumn = false;
       
        for (int i=0; i<C; i++){
            if (matrix[0][i] == 0) {
                isFirstRow = true;
                break;
            }
        }
       
        for (int i=0; i<R; i++){
            if (matrix[i][0] == 0){
                isFirstColumn = true;
                break;
            }
        }
       
        for (int r=1; r<R; r++){
            for (int c=1; c<C; c++){
                if (matrix[r][c] == 0){
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }
       
       
        for (int r=1; r<R; r++){
            for (int c=1; c<C; c++){
                if (matrix[r][0] == 0 || matrix[0][c] == 0) matrix[r][c] = 0;
            }
        }
       
        if (isFirstRow) {
            for (int c=0; c<C; c++) matrix[0][c] = 0;
        }
       
        if (isFirstColumn){
            for (int r=0; r<R; r++) matrix[r][0] = 0;
        }
    }
};    
       
    }
};