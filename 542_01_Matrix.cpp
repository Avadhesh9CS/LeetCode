/*
542. 01 Matrix
Medium
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

Constraints:
    m == mat.length
    n == mat[i].length
    1 <= m, n <= 104
    1 <= m * n <= 104
    mat[i][j] is either 0 or 1.
    There is at least one 0 in mat.
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(),t,l,b,r,INF=n+m;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(mat[i][j]){
                   t=INF,l=INF;
                   if(i-1>=0) t=mat[i-1][j];
                   if(j-1>=0) l=mat[i][j-1];
                   mat[i][j]=min(t,l)+1;
               } 
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                b=INF,r=INF;
                if(i+1<m) b=mat[i+1][j]; 
                if(j+1<n) r=mat[i][j+1];
                mat[i][j]=min(mat[i][j],min(b,r)+1);
            }
        }
        return mat;
    }
};
