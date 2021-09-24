#include<bits/stdc++.h>
#include<iostream>

using namespace std;

vector<int>getElementsFromBorder(vector<vector<int>>&matrix, int row_start, int row_end, int column_start, int column_end){
    vector<int>result;
    //getting corner elements
    result.push_back(matrix[row_start][column_start]);
    result.push_back(matrix[row_start][column_end]);
    result.push_back(matrix[row_end][column_start]);
    result.push_back(matrix[row_end][column_end]);
    
    for(int i=row_start+1;i<row_end;i++){
        result.push_back(matrix[i][column_start]);
    }
    
    for(int i=row_start+1;i<row_end;i++){
        result.push_back(matrix[i][column_end]);
    }
    
    for(int i=column_start+1;i<column_end;i++){
        result.push_back(matrix[row_start][i]);
    }
    
    for(int i=column_start+1;i<column_end;i++){
        result.push_back(matrix[row_end][i]);
    }
    sort(result.begin(),result.end());
    return result;
}

void fill_result_matrix(vector<vector<int>>&result, int row_start, int row_end, int column_start, int column_end, vector<int>&temp){
    int idx = 0;
    for(int i=column_start;i<=column_end;i++)result[row_start][i] = temp[idx++];
    row_start+=1;
    for(int i=row_start;i<=row_end;i++)result[i][column_end] = temp[idx++];
    column_end-=1;
    for(int i=column_end;i>=column_start;i--)result[row_end][i] = temp[idx++];
    row_end-=1;
    for(int i=row_end; i>=row_start;i--)result[i][column_start] = temp[idx++];
}

vector<vector<int>> borderSort(vector<vector<int>>& matrix) {
    vector<vector<int>>result(matrix.size(),vector<int>(matrix.size(),0));
    int row_start = 0, row_end = matrix.size()-1, column_start = 0, column_end = matrix[0].size()-1;
    
    while(row_start<row_end && column_start < column_end){
        
        vector<int>temp = getElementsFromBorder(matrix,row_start,row_end,column_start,column_end);
        fill_result_matrix(result,row_start, row_end, column_start, column_end, temp);
        
        row_start+=1;
        row_end-=1;
        column_start+=1;
        column_end-=1;
    }
    return result;
}

int main(){
    vector<vector<int>>matrix = {{1,2,3,4},{5,6,7,-8},{9,10,11,-12},{913,14,215,16}};
    matrix = borderSort(matrix);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}

