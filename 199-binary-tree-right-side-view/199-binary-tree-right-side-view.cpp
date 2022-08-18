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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int> p=q.front();
            q.pop();
            TreeNode* frontNode=p.first;
            int lvl=p.second;
            mp[lvl]=frontNode->val;
            if(frontNode->left) q.push({frontNode->left,lvl+1});
            if(frontNode->right) q.push({frontNode->right,lvl+1});
        }
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};