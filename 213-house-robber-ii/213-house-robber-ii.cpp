class Solution {
public:
    int solve(vector<int>& nums){
        int n=nums.size();
        int prev2=0;
        int prev1=nums[0];
        
        for(int i=1;i<n;i++){
            int incl=prev2+nums[i];
            int excl=prev1+0;
            int ans=max(incl,excl);
            prev2=prev1;
            prev1=ans;
            
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> temp1(nums.begin(),nums.end()-1);
        vector<int> temp2(nums.begin()+1,nums.end());
        
        return max(solve(temp1),solve(temp2));
    }
};