class Solution {
public:
    int dp[1000];
    int solve(int i,vector<int>& cost){
        int ans=0;
        if(i+1==cost.size()) return cost[i];
        if(i+2==cost.size()) return cost[i];
        if(dp[i]!=-1) return dp[i];
        ans= cost[i]+min(solve(i+1,cost),solve(i+2,cost));
        return dp[i]=ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof dp);
        return min(solve(0,cost),solve(1,cost));
    }
};