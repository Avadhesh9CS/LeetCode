//530. Minimum Absolute Difference in BST
/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1

Constraints:
    The number of nodes in the tree is in the range [2, 104].
    0 <= Node.val <= 105
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
class Solution {
    TreeNode *pre=NULL;
    int mindiff=INT_MAX,diff;
    void inorderSearch(TreeNode* root){
        if(!root){
            return;
        }
        inorderSearch(root->left);
        diff=abs(root->val-pre->val);
        if(root!=pre && diff<mindiff){
            mindiff=diff;
        }
        pre=root;
        inorderSearch(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        pre=root;
        inorderSearch(root);
        return mindiff;
    }
};
