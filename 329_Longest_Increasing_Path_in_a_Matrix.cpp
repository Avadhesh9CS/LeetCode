/*
329. Longest Increasing Path in a Matrix
Hard

Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Example 1:
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:
Input: matrix = [[1]]
Output: 1

Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 200
    0 <= matrix[i][j] <= 231 - 1
*/
class Solution {
    vector<vector<int>>dp;
    int findis(vector<vector<int>>& matrix,int i,int j){
        if(dp[i][j]>0) return dp[i][j];
        int curr=matrix[i][j];
        int mx=0;
        if(i+1<matrix.size() && matrix[i+1][j]>curr)
            mx=max(mx,findis(matrix,i+1,j));
        if(i-1>=0 && matrix[i-1][j]>curr)
            mx=max(mx,findis(matrix,i-1,j));    
        if(j+1<matrix[0].size() && matrix[i][j+1]>curr)
            mx=max(mx,findis(matrix,i,j+1));
        if(j-1>=0 && matrix[i][j-1]>curr)
            mx=max(mx,findis(matrix,i,j-1));

        dp[i][j]=mx+1;
        return mx+1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),mx=0,d;
        dp=vector<vector<int>>(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                d=findis(matrix,i,j);
                mx=max(mx,d);
            }
        }
      return mx;  
    }
};
