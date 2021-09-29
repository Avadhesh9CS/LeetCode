/*
931. Minimum Falling Path Sum
Medium

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum underlined below:
[[2,1,3],      [[2,1,3],
 [6,5,4],       [6,5,4],
 [7,8,9]]       [7,8,9]]

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is underlined below:
[[-19,57],
 [-40,-5]]

Example 3:
Input: matrix = [[-48]]
Output: -48

Constraints:
    n == matrix.length
    n == matrix[i].length
    1 <= n <= 100
    -100 <= matrix[i][j] <= 100
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m,i,j,y;
        vector<int> mi(matrix[0].size(),0);
        int d[3]={-1,0,1};
        for(i=n-2;i>=0;i--){
            for(j=0;j<n;j++){
                m=INT_MAX;
                for(int k:d){
                    y=j+k;
                    if(y>=0 && y<n){
                        m=min(matrix[i+1][y]+matrix[i][j],m);
                    }
                }
                matrix[i][j]=m;
            }
        }
        return *min_element(matrix[0].begin(),matrix[0].end());
    }
};
