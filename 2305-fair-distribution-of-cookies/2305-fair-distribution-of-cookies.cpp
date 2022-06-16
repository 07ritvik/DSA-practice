class Solution {
public:
    void solve(int ind,vector<int> &c,vector<int> &kval,int &ans){
        if(ind==c.size()){
            ans=min(ans, *max_element(kval.begin(),kval.end()));
            return;
        }
        for(int i=0;i<kval.size();i++){
            kval[i]+=c[ind];
            solve(ind+1,c,kval,ans);
            kval[i]-=c[ind];
        }
        
    }
    
    int distributeCookies(vector<int>& c, int k) {
        int n=c.size();
        vector<int> kval(k);
        int ans=INT_MAX;
        solve(0,c,kval,ans);
        return ans;
    }
};