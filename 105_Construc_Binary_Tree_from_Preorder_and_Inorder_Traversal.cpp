/*
105. Construct Binary Tree from Preorder and Inorder Traversal
Medium

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1] 

Constraints:

    1 <= preorder.length <= 3000
    inorder.length == preorder.length
    -3000 <= preorder[i], inorder[i] <= 3000
    preorder and inorder consist of unique values.
    Each value of inorder also appears in preorder.
    preorder is guaranteed to be the preorder traversal of the tree.
    inorder is guaranteed to be the inorder traversal of the tree.
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
     TreeNode* build(vector<int>& preorder,int pi,int pj, vector<int>& inorder,int ii,int ij){
         if(pi>=pj || ii>=ij) return NULL;
         int mid=preorder[pi];
         auto f=find(inorder.begin()+ii,inorder.begin()+ij,mid);
         int dis=f-inorder.begin()-ii;
         TreeNode* node=new TreeNode(mid);
         node->left=build(preorder,pi+1,pi+1+dis,inorder,ii,ii+dis+1);
         node->right=build(preorder,pi+1+dis,pj,inorder,ii+dis+1,ij);
         return node;
     }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
};
