//144. Binary Tree Preorder Traversal
/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
Input: root = [1,2]
Output: [1,2]

Example 5:
Input: root = [1,null,2]
Output: [1,2]

Constraints:
    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
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
    void preorderTraversalHelper(TreeNode* root,vector<int> &output){
        if(!root){
            return;
        }
        output.push_back(root->val);
        preorderTraversalHelper(root->left,output);
        preorderTraversalHelper(root->right,output);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        preorderTraversalHelper(root, output);
        return output;      
    }
};


//Morris Traversal
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
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ans;
        TreeNode* pre=NULL;
        while(root){
            if(root->left){
                pre=root->left;
                while(pre->right && pre->right!=root){
                    pre=pre->right;
                }
                if(!pre->right){
                    ans.push_back(root->val);
                    pre->right=root;
                    root=root->left;
                }else{
                    pre->right=NULL;
                    root=root->right;
                }
            }
            else{
                ans.push_back(root->val);
                root=root->right;
            }
        }
    return ans;
        
    }
};