//145. Binary Tree Postorder Traversal
/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
Input: root = [1,2]
Output: [2,1]

Example 5:
Input: root = [1,null,2]
Output: [2,1]

Constraints:
    The number of the nodes in the tree is in the range [0, 100].
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
    void postorderTraversalHelper(TreeNode* root,vector<int> &output){
        if(!root){
            return;
        }
        postorderTraversalHelper(root->left,output);
        postorderTraversalHelper(root->right,output);
        output.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        postorderTraversalHelper(root,output); 
        return output;
    }
};

//Solution 2->Morris Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        TreeNode* dummy=new TreeNode(-1);
        dummy->left=root;
        TreeNode* curr= dummy;
        TreeNode* pre=NULL;
        TreeNode* prev=NULL;
        TreeNode* succ=NULL;
        TreeNode* temp=NULL;
        while(curr){
            if(curr->left){
                pre=curr->left;
                while(pre->right && pre->right!=curr){
                    pre=pre->right;
                }
                if(!pre->right){
                    pre->right=curr;
                    curr=curr->left;
                }else{
                    pre->right=NULL;
                    succ=curr;
                    curr=curr->left;
                    prev=NULL;
                    
                    while(curr){
                        temp=curr->right;
                        curr->right=prev;
                        prev=curr;
                        curr=temp;
                    }
                    
                    while(prev){
                        output.push_back(prev->val);
                        temp=prev->right;
                        prev->right=curr;
                        curr=prev;
                        prev=temp;
                    }
                    curr=succ;
                    curr=curr->right;
                }
                
            }else{
                curr=curr->right;
            }    
        }
     return output;   
    }
};
