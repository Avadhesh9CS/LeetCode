/*
378. Kth Smallest Element in a Sorted Matrix
Medium

Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example 1:
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Example 2:
Input: matrix = [[-5]], k = 1
Output: -5

Constraints:
    n == matrix.length
    n == matrix[i].length
    1 <= n <= 300
    -109 <= matrix[i][j] <= 109
    All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
    1 <= k <= n2
*/
class Solution { 
    int count(vector<vector<int>>& matrix, int x){
        int cnt=0,j=n-1;
        for(int i=0;i<m;i++){
            while(j>=0 && matrix[i][j]>x) --j;
            cnt+=(j+1);
        }
        return cnt;
    }
public:
    int m, n;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m=matrix.size(),n=matrix[0].size();
        int ans=-1;
        int left=matrix[0][0],right=matrix[n-1][m-1],mid;
        while(left<=right){
            mid=left+((right-left)/2);
            if(count(matrix,mid)>=k){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};
