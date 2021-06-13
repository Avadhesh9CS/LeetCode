//501. Find Mode in Binary Search Tree    
/*
Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
If the tree has more than one mode, return them in any order.
//501. Find Mode in Binary Search
Assume a BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than or equal to the node's key.
    The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [1,null,2,2]
Output: [2]

Example 2:
Input: root = [0]
Output: [0]

Constraints:
    The number of nodes in the tree is in the range [1, 104].
    -10^5 <= Node.val <= 10^5
Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
    int nf=0,f=0;
    vector<int> output;
    void inorder(TreeNode *root){
        if(!root){
            return;
        }
        inorder(root->left);
        if(pre->val==root->val){
            f++;
        }
        else{
            if(nf==f){
                output.push_back(pre->val);
            }else if(pre && nf<f){
                output={pre->val};
                nf=f;
            }
            f=1;
        }
        pre=root;
        inorder(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        pre=root;
        inorder(root);
        if(nf==f && pre->val!=output[output.size()-1]){
            output.push_back(pre->val);
        }else if(nf<f){
            output={pre->val};
        }
        return output;
    }
};
