class Solution {
public:
    bool isPalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void solve(int ind,string s,vector<string> &v,vector<vector<string>> &ans){
        if(ind==s.size()){
            ans.push_back(v);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                v.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,v,ans);
                v.pop_back();
            }
        }
    }
        
    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> ans;
        solve(0,s,v,ans);
        return ans;
    }
};