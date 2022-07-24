class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        // if(n==1) return nums[0];
        vector<int> dp(n,0);
        dp[0]=nums[0];
        if(n>1) dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int incl=dp[i-2]+nums[i];
            int excl=dp[i-1]+0;
            dp[i]=max(incl,excl);
        }
        return dp[n-1];
    }
};