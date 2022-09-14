class Solution {
public:
//     int solve(int ind,vector<int>& days, vector<int>& costs,vector<int> &dp){
//         if(ind>=days.size()) return 0;
//         if(dp[ind]!=-1) return dp[ind];
//         //1 DAY
//         int opt1=costs[0]+solve(ind+1,days,costs,dp);
        
//         //7 DAYS
//         int i;
//         for(i=ind;i<days.size() &&days[i]<days[ind]+7;i++);
//         int opt2=costs[1] + solve(i,days,costs,dp);
        
//         //30 DAYS
//         for(i=ind;i<days.size() &&days[i]<days[ind]+30;i++);
//         int opt3=costs[2] + solve(i,days,costs,dp);
        
//         return dp[ind]=min({opt1,opt2,opt3});
//     }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int> dp(days.size(),-1);
        // return solve(0,days,costs,dp);
//         int n=days.size();
//         vector<int> dp(n+1,INT_MAX);
//         dp[n]=0;
        
//         for(int i=n-1;i>=0;i--){
//             int opt1=costs[0] + dp[i+1];
            
//             int j;
//             for(j=i;j<n&&days[j]<days[i]+7;j++);
//             int opt2=costs[1] + dp[j];
            
            
//             for(j=i;j<n&&days[j]<days[i]+30;j++);
//             int opt3=costs[2] + dp[j];
            
//             dp[i]=min({opt1,opt2,opt3});
           
//         }
//         return dp[0];
        
        int ans=0;
        
        queue<pair<int,int>> month;
        queue<pair<int,int>> week;
        
        
        for(int day: days){
            while(!month.empty() && month.front().first+30<=day)
                month.pop();
            while(!week.empty() && week.front().first+7<=day)
                week.pop();
            
            week.push({day,ans+costs[1]});
            month.push({day,ans+costs[2]});
            
            ans=min(ans+costs[0],min(week.front().second,month.front().second));
        }
        return ans;
    }
};