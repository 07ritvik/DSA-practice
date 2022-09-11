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
    int solve(TreeNode* root,unordered_map<TreeNode*,int> &mp){
        if(root==NULL) return 0;
        if(mp.find(root)!=mp.end()) return mp[root];
        
        int left=0,right=0;
        if(root->left){
            left=solve(root->left->left,mp) +solve(root->left->right,mp);
        }
        if(root->right){
            right=solve(root->right->left,mp)+ solve(root->right->right,mp);
        }
        
        return mp[root]=max(root->val+left+right,(solve(root->left,mp)+solve(root->right,mp)));
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> mp;
        return solve(root,mp);
    }
};