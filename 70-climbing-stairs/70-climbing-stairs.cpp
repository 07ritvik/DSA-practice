class Solution {
    int ways(int i, int n, vector<int>& dp)
    {
        if(i==n) return 1;
        if(i>n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int left = ways(i+1,n,dp);
        int right = ways(i+2,n,dp);
        
        dp[i] = left+right;
        return dp[i];
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return ways(0,n,dp);
    }
};