//572. Subtree of Another Tree
/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false

Constraints:
    The number of nodes in the root tree is in the range [1, 2000].
    The number of nodes in the subRoot tree is in the range [1, 1000].
    -10^4 <= root.val <= 10^4
    -10^4 <= subRoot.val <= 10^4
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
    bool isTreeEqual(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot){
            return true;
        }else if(root && subRoot){
            if(root->val!=subRoot->val){
                return false;
            }
        bool left=isTreeEqual(root->left?root->left:NULL,subRoot->left?subRoot->left:NULL);
        bool right=isTreeEqual(root->right?root->right:NULL,subRoot->right?subRoot->right:NULL);
        return left && right;
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot){
            return true;
        }
        if(!root && subRoot){
            return false;
        }
        if(root->val==subRoot->val){
            bool check= isTreeEqual(root,subRoot);
            if(check){
                return true;
            }
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);     
    }
};
