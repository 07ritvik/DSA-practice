class Solution {
public:
//     int solve(int i,int lane,vector<int>& obs,vector<vector<int>> &dp){
//         if(i==obs.size()-1) return 0;
    
//         if(dp[lane][i]!=-1) return dp[lane][i];
        
//         if(obs[i+1]!=lane)  {
//             return dp[lane][i]=solve(i+1,lane,obs,dp);
//         }
//         else{
//             int ans=INT_MAX;
//             for(int j=1;j<=3;j++){
//                 if(obs[i]!=j && j!=lane){
//                    ans=min(ans,1+solve(i,j,obs,dp))  ;
//                 }
//             }
//             return dp[lane][i]=ans;
//         }
//     }
    
    
// //     Tab
//             int n=obs.size()-1;
//         vector<vector<int>> dp(4,vector<int>(obs.size(),INT_MAX));
        
//         dp[0][n]=0;
//         dp[1][n]=0;
//         dp[2][n]=0;
//         dp[3][n]=0;
        
//         for(int i=n-1;i>=0;i--){
//             for(int lane=1;lane<=3;lane++){
                
//                 if(obs[i+1]!=lane){
//                     dp[lane][i]=dp[lane][i+1];
                    
//                 }
//                 else{
//                     int ans=INT_MAX;
//                     for(int j=1;j<=3;j++){
//                         if(obs[i]!=j && lane!=j){
//                          ans=min(ans,1+dp[j][i+1]);   
//                         }
//                     }
//                     dp[lane][i]=ans;
//                 }
//             }
//         }
//         return min({dp[2][0],1+dp[1][0],1+dp[3][0]});
    
    
    int minSideJumps(vector<int>& obs) {
        // vector<vector<int>> dp(4,vector<int>(obs.size(),-1));
        // return solve(0,2,obs,dp);
        int n=obs.size()-1;
        // vector<vector<int>> dp(4,vector<int>(obs.size(),INT_MAX));
        
        vector<int> curr(4,INT_MAX);
        vector<int> next(4,INT_MAX);
        
        next[0]=0;
        next[1]=0;
        next[2]=0;
        next[3]=0;
        
        for(int i=n-1;i>=0;i--){
            for(int lane=1;lane<=3;lane++){
                
                if(obs[i+1]!=lane){
                    curr[lane]=next[lane];
                    
                }
                else{
                    int ans=INT_MAX;
                    for(int j=1;j<=3;j++){
                        if(obs[i]!=j && lane!=j){
                         ans=min(ans,1+next[j]);   
                        }
                    }
                    curr[lane]=ans;
                }
            }
            next=curr;
        }
        return min({curr[2],1+curr[1],1+curr[3]});

    }
};