class Solution {
public:
    int solve(int i,int j,vector<int>& values,vector<vector<int>> &dp){
        if(i+1==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,(values[i]*values[j]*values[k]) + solve(i,k,values,dp) + solve(k,j,values,dp));
        }
        return dp[i][j]=ans;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size(),vector<int>(values.size(),-1));
        return solve(0,values.size()-1,values,dp);
    }
};