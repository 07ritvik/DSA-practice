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
    void solve(TreeNode* root,int mx,int &ans){
        if(root==NULL){
            return;
        }
        if(root->val>=mx){
            ans++;
        }
        solve(root->left,max(mx,root->val),ans);
        solve(root->right,max(mx,root->val),ans);
    }
    
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int mx=root->val;
        int ans=0;
        solve(root,mx,ans);
        return ans;
    }
};