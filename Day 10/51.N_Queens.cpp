class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        string s(n, '.');
        vector<string>board(n);
        vector<vector<string>>result;
        for(int i=0;i<n;i++) board[i]=s;
        
        solve(0,board,result,n);
        return result;
  
    }
private:
    void solve(int col, vector<string>&board, vector<vector<string>>&result,int n){
        if(col==n){
            result.push_back(board);
            return;
        }
        
        for(int row = 0; row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,result,n);
                board[row][col]='.';
            }
        }
        
    }
    
    bool isSafe(int row, int col, vector<string>&board, int n){
        int r = row;
        int c = col;
        
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        
        row = r;
        col = c;
        
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q')return false;
            row--;
            col--;
        }
        
        row = r;
        col = c;
        
        while(row<n && col>=0){
            if(board[row][col] == 'Q')return false;
            row++;
            col--;
        }
        return true;
    }
    
};