//653. Two Sum IV - Input is a BST
/*
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

Example 3:
Input: root = [2,1,3], k = 4
Output: true

Example 4:
Input: root = [2,1,3], k = 1
Output: false

Example 5:
Input: root = [2,1,3], k = 3
Output: true

Constraints:
    The number of nodes in the tree is in the range [1, 104].
    -104 <= Node.val <= 104
    root is guaranteed to be a valid binary search tree.
    -105 <= k <= 105
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
    vector<int> sortedArray;
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        sortedArray.push_back(root->val);
        inorder(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return false;
        }
        inorder(root);
        int low=0,high=sortedArray.size()-1;
        while(low<high){
            if(sortedArray[low]+sortedArray[high]==k){
                return true;
            }else if(sortedArray[low]+sortedArray[high]>k){
                high--;
            }else{
                low++;
            }
        }
        return false;
    }
};
