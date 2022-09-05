/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node* root,vector<vector<int>> &ans){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            
            if(temp!=NULL){
                v.push_back(temp->val);
                int n=temp->children.size();
                for(int i=0;i<n;i++){
                    q.push(temp->children[i]);
                }
                
            }
            else{
                if(!v.empty()){
                    ans.push_back(v);
                    v.clear();
                    q.push(NULL);
                }
            }
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        solve(root,ans);
        return ans;
    }
};