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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int &index,int inorderStart,int inorderEnd,int n,map<int,int> &mp){
        if(index<0 || inorderStart>inorderEnd){
            return NULL;
        }
        int element=postorder[index--];
        TreeNode* root=new TreeNode(element);
        int position=mp[element];
        root->right=solve(inorder,postorder,index,position+1,inorderEnd,n,mp);
        root->left=solve(inorder,postorder,index,inorderStart,position-1,n,mp);
        
        return root;
    }    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        int n=inorder.size();
        int index=n-1;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
       
        TreeNode* ans=solve(inorder,postorder,index,0,n-1,n,mp);
        return ans;   
    }
};