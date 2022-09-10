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
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        
        TreeNode *left,*right;
        left=pruneTree(root->left);
        right=pruneTree(root->right);
        left?root->left=left:root->left=NULL;
        right?root->right=right:root->right=NULL;
        
        if(!root->left && !root->right && root->val==0){
            return NULL;
        }
        return root;
 
        
    }
};