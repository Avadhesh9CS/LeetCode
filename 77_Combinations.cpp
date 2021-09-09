/*
77. Combinations
Medium

Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Example 2:
Input: n = 1, k = 1
Output: [[1]]

Constraints:
    1 <= n <= 20
    1 <= k <= n
*/
class Solution {
    void helper(int start,int n,int k,vector<int> &arr,vector<vector<int>> &ans){
        if(k==0){
            ans.push_back(arr);
            return;
        }
        for(int i=start;i<=n;i++){
            arr.push_back(i);
            helper(i+1,n,k-1,arr,ans);
            arr.pop_back();
        }        
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> arr;
        helper(1,n,k,arr,ans);
        return ans;
    }
};
