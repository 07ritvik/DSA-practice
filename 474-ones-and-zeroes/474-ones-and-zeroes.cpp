class Solution {
public:
    int solve(int ind,vector<string>& strs, int m, int n,vector<vector<vector<int>>> &dp){
        if(ind>=strs.size() || m<0 || n<0) return 0;
        int c1=0,c2=0;
 
            string s=strs[ind];
            for(int j=0;j<s.size();j++){
                if(s[j]=='1') c2++;
                else c1++;
            }
        if(dp[ind][m][n]!=-1) return dp[ind][m][n];    
        if(m-c1>=0 && n-c2>=0){
            return dp[ind][m][n]= max(1+solve(ind+1,strs,m-c1,n-c2,dp),solve(ind+1,strs,m,n,dp));
        }
        return dp[ind][m][n]=solve(ind+1,strs,m,n,dp);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
       
        return solve(0,strs,m,n,dp);
  
    }
};