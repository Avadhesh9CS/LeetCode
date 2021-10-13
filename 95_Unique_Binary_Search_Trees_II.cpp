/*
95. Unique Binary Search Trees II
Medium

Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

Example 1:
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Example 2:
Input: n = 1
Output: [[1]]

Constraints:
    1 <= n <= 8
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
vector<vector<vector<TreeNode*>>> dp(10,vector<vector<TreeNode*>>(10));
class Solution {
    vector<TreeNode*> helper(int start,int end){      
        if(dp[start][end].size()) return dp[start][end];
        if(start>end){
            dp[start][end]={NULL};
            return dp[start][end];
        }
        vector<TreeNode*> res;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left=helper(start,i-1);
            vector<TreeNode*> right=helper(i+1,end);
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
            }
        }
        dp[start][end]=res;
        return dp[start][end];
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};
