class Solution {
public:
    void solve(int ind,string digits,vector<string> v,vector<string> &ans,string &s){
        if(ind==digits.size()){
            ans.push_back(s);
            return;
        }
        char d=digits[ind];
        string str=v[d-'0'];
        for(int i=0;i<str.size();i++){
            char temp=str[i];
            s+=temp;
            solve(ind+1,digits,v,ans,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(n==0) return {};
        string s="";
        vector<string> ans;
        vector<string> v={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,digits,v,ans,s);
        return ans;
        
    }
};