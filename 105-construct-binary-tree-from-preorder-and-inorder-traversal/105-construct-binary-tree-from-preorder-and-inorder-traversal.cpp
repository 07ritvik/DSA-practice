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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int inorderStart,int inorderEnd,int n,map<int,int> &mp){
        if(index>=n || inorderStart>inorderEnd){
            return NULL;
        }
        int element=preorder[index++];
        TreeNode* root=new TreeNode(element);
        int position=mp[element];
        root->left=solve(preorder,inorder,index,inorderStart,position-1,n,mp);
        root->right=solve(preorder,inorder,index,position+1,inorderEnd,n,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        int n=inorder.size();
        int index=0;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* ans=solve(preorder,inorder,index,0,n-1,n,mp);
        return ans;
    }
};