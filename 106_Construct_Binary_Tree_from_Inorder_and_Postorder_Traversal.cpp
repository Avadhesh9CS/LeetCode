/*
106. Construct Binary Tree from Inorder and Postorder Traversal
Medium

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]

Constraints:
    1 <= inorder.length <= 3000
    postorder.length == inorder.length
    -3000 <= inorder[i], postorder[i] <= 3000
    inorder and postorder consist of unique values.
    Each value of postorder also appears in inorder.
    inorder is guaranteed to be the inorder traversal of the tree.
    postorder is guaranteed to be the postorder traversal of the tree.
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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int &rootind,int start,int end){
        if(start>end)return NULL;
        int mid=postorder[rootind];
        TreeNode *root=new TreeNode(mid);
        auto f=find(inorder.begin()+start,inorder.begin()+end,mid);
        int dis=f-inorder.begin()-start;
        rootind--;
         root->right=helper(inorder,postorder,rootind,start+dis+1,end);
        root->left=helper(inorder,postorder,rootind,start,start+dis-1);    
        return root;
    } 
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootind=postorder.size()-1;
        return helper(inorder,postorder,rootind,0,inorder.size()-1);
    }
};
