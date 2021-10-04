/*
59. Spiral Matrix II
Medium
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]

Constraints:
    1 <= n <= 20
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int row=n,col=n,i=0,j=0,count=1;
        while(i<row && j<col){
            for(int l=j;l<col;l++){
                ans[i][l]=count++;
            }
            i++;
            for(int k=i;k<row;k++){
                ans[k][col-1]=count++;
            }
            col--;
            for(int l=col-1;l>=j;l--){
                ans[row-1][l]=count++;
            }
            row--;
            for(int k=row-1;k>=i;k--){
                ans[k][j]=count++;
            }
            j++;            
        }
        return ans;
    }
};
