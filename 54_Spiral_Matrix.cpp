/*-
54. Spiral Matrix
Medium

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=0,n=matrix.size()-1,k=0,l=matrix[0].size()-1;
        while(m<=n && k<=l){
            for(int j=k;j<=l;j++){
                res.push_back(matrix[m][j]);
            }
            m++;
            for(int i=m;i<=n;i++){
                res.push_back(matrix[i][l]);
            }
            l--;
            if(m<=n){
                for(int j=l;j>=k;j--){
                    res.push_back(matrix[n][j]);
                }
            }
            n--;
            if(k<=l){
                for(int i=n;i>=m;i--){
                    res.push_back(matrix[i][k]);
                }
            }
            k++;
        }
        return res;
    }
};
