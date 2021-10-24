/*
51. N-Queens
Hard

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]

Constraints:
    1 <= n <= 9
*/
class Solution {
    vector<vector<string>> ans;
    bool isSafe(int row,int col,vector<string>& board){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q')
                return false;
        }
        int i=row-1,j=col-1;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')
                return false;
            j--;
            i--;
        }
        i=row-1,j=col+1;
        while(i>=0 && j<board[0].size()){
            if(board[i][j]=='Q')
                return false;
            i--;
            j++;
        }
        return true;
    }
    void helper(int row,int size,vector<string>& board){
        if(row==size){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<size;j++){
            if(isSafe(row,j,board)){
                board[row][j]='Q';
                helper(row+1,size,board);
                board[row][j]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string s=string(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        helper(0,n,board);
        return ans;
    }
};
