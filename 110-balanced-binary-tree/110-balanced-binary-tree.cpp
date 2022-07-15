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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int h1=height(root->left);
        int h2=height(root->right);
        return max(h1,h2)+1;
    }
    pair<bool,int> fast(TreeNode* root){
        if(root==NULL){
            pair<bool,int> p={true,0};
            return p;
        }
        pair<bool,int> left=fast(root->left);
        pair<bool,int> right=fast(root->right);
        
        bool leftAns=left.first;
        bool rightAns=right.first;
        bool diff=abs(left.second-right.second)<=1;
        
        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1;
        
        if(leftAns&&rightAns&&diff)  ans.first=true;
        else ans.first=false;
        
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return fast(root).first;
    }
};