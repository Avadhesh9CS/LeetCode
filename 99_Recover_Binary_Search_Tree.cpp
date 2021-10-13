/*
99. Recover Binary Search Tree
Medium

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Example 1:
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Example 2:
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

Constraints:
    The number of nodes in the tree is in the range [2, 1000].
    -231 <= Node.val <= 231 - 1 
Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?
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
public:
    void recoverTree(TreeNode* root) {
        TreeNode* pre=NULL,*first=NULL,*second=NULL,*temp=NULL;
        while(root){
            if(root->left){
                temp=root->left;
                while(temp->right && temp->right!=root){
                    temp=temp->right;
                }
                if(temp->right){
                    if(pre && pre->val>root->val){
                        if(!first){first=pre;second=root;}
                        else{second=root;}
                    }
                    pre=root;
                    temp->right=NULL;
                    root=root->right;
                    
                }else{
                    temp->right=root;
                    root=root->left;
                }
            }else{
                if(pre && pre->val>root->val){
                        if(!first){first=pre;second=root;}
                        else{second=root;}
                    }
                pre=root;
                root=root->right;
            }
        }
        if(first && second){
            int t=first->val;
            first->val=second->val;
            second->val=t;
        }
    }
};
