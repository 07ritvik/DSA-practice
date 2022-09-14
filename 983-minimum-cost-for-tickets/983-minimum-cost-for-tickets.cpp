class Solution {
public:
    int solve(int ind,vector<int>& days, vector<int>& costs,vector<int> &dp){
        if(ind>=days.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        //1 DAY
        int opt1=costs[0]+solve(ind+1,days,costs,dp);
        
        //7 DAYS
        int i;
        for(i=ind;i<days.size() &&days[i]<days[ind]+7;i++);
        int opt2=costs[1] + solve(i,days,costs,dp);
        
        //30 DAYS
        for(i=ind;i<days.size() &&days[i]<days[ind]+30;i++);
        int opt3=costs[2] + solve(i,days,costs,dp);
        
        return dp[ind]=min({opt1,opt2,opt3});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(),-1);
        return solve(0,days,costs,dp);
    }
};