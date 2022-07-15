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
    void inorder(TreeNode* root,unordered_map<TreeNode*,int> &mp,int &ans){
        if(root==NULL) return;
        inorder(root->left,mp,ans);
        if(mp.find(root)==mp.end()){
            ans++;
            mp[root]++;
        }
        inorder(root->right,mp,ans);
    }
    int countNodes(TreeNode* root) {
        unordered_map<TreeNode*,int> mp;
        int ans=0;
        inorder(root,mp,ans);
        return ans;
    }
};