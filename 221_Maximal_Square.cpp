/*
221. Maximal Square
Medium

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:

Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:

Input: matrix = [["0"]]
Output: 0

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 300
    matrix[i][j] is '0' or '1'.
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size(),col=matrix[0].size(),mx=0,pre,temp;
        vector<int> dp(col,0);
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                temp=dp[c];
                if(!r || !c || matrix[r][c]=='0'){
                    dp[c]=matrix[r][c]-'0';
                }else{
                    dp[c]=1+min(min(pre,dp[c-1]),dp[c]);
                }
                mx=max(mx,dp[c]);
                pre=temp;
            }
        }
        return mx*mx;
    }
};
