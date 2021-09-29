/*
1314. Matrix Block Sum
Medium
Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

    i - k <= r <= i + k,
    j - k <= c <= j + k, and
    (r, c) is a valid position in the matrix.

Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

Example 2:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n, k <= 100
    1 <= mat[i][j] <= 100
*/
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0)),ans(m,vector<int>(n,0));
        int sum;
        for(int j=0;j<n;j++){
            sum=0;
            for(int i=0;i<m;i++){
                if(sum==0){
                    for(int l=0;l<=k && i+l<m;l++){
                        sum+=mat[i+l][j];
                    }
                }else{
                      sum-=(i-k-1>=0?mat[i-k-1][j]:0);  
                      sum+=(i+k<m?mat[i+k][j]:0);
                }
                dp[i][j]=sum;            
            }
        }
        for(int i=0;i<m;i++){
            sum=0;
            for(int j=0;j<n;j++){
                if(sum==0){
                    for(int l=0;l<=k && j+l<n;l++){
                        sum+=dp[i][j+l];
                    }
                }else{
                      sum-=(j-k-1>=0?dp[i][j-k-1]:0);  
                      sum+=(j+k<n?dp[i][j+k]:0);
                }
                ans[i][j]=sum;     
            }
        }
        return ans;
    }
};
