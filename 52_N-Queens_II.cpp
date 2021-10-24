/*
52. N-Queens II
Hard

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:
Input: n = 1
Output: 1

Constraints:
    1 <= n <= 9
*/
class Solution {
    int count=0;
    bool isSafe(int row,int col,vector<vector<int>>& board){
        for(int i=0;i<row;i++){
            if(board[i][col]==1)
                return false;
        }
        int i=row-1,j=col-1;
        while(i>=0 && j>=0){
            if(board[i][j]==1)
                return false;
            j--;
            i--;
        }
        i=row-1,j=col+1;
        while(i>=0 && j<board[0].size()){
            if(board[i][j]==1)
                return false;
            i--;
            j++;
        }
        return true;
    }
    void helper(int row,int size,vector<vector<int>>& board){
        if(row==size){
            count++;
            return;
        }
        for(int j=0;j<size;j++){
            if(isSafe(row,j,board)){
                board[row][j]=1;
                helper(row+1,size,board);
                board[row][j]=0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        helper(0,n,board);
        return count;
    }
};

