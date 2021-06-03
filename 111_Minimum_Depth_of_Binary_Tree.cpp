//111. Minimum Depth of Binary Tree
/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5

Constraints:
    The number of nodes in the tree is in the range [0, 105].
    -1000 <= Node.val <= 1000
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
struct qitem{
    TreeNode* node;
    int depth;
};
//Solution 1
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<qitem> q;
        qitem qi={root,1};
        q.push(qi);
        
        while(!q.empty()){
            qi=q.front();
            q.pop();
            TreeNode* t=qi.node;
            int depth=qi.depth;
            
            if(!t->left && !t->right)
                return depth;
            
            if(t->left){
                qi.node=t->left;
                qi.depth=1+depth;
                q.push(qi);
            }
            if(t->right){
                qi.node=t->right;
                qi.depth=1+depth;
                q.push(qi);
            }    
        }
        return 0;
    }
};


//Solution 2
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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right){
            return 1;
        }
        int l=INT_MAX,r=INT_MAX;
        if(root->left){
            l=minDepth(root->left);
        }
        if(root->right){
            r=minDepth(root->right);
        }
        return min(l,r)+1;
    }
};
