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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        map<int,map<int,vector<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp=q.front();
            q.pop();
            TreeNode* frontNode=temp.first;
            int lvl=temp.second.second;
            int hd=temp.second.first;
            
            mp[hd][lvl].push_back(frontNode->val);
            if(frontNode->left) q.push({frontNode->left,{hd-1,lvl+1}});
            if(frontNode->right) q.push({frontNode->right,{hd+1,lvl+1}});
            
        }
        
        
        for(auto i:mp){
            vector<int> v;
            for(auto j:i.second){
                sort(j.second.begin(),j.second.end());
                for(auto k:j.second){
                    v.push_back(k);
                }
            }
            
            ans.push_back(v);
        }
        return ans;
    }
};