class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++) sum+=nums[i];
        sum=sum-x;
        if(sum<0) return -1;
        if(sum==0) return nums.size();
        
        int i=0,j=0;
        int curr=0;
        int ans=-1;
        while(j<n){
            curr+=nums[j];
            if(curr<sum) j++;
            else if(curr==sum){
                ans=max(ans,j-i+1);
                j++;
            }
            else if(curr>sum){
                while(curr>sum){
                    curr-=nums[i];
                    i++;
                    if(curr==sum) ans=max(ans,j-i+1);
                }
                j++;
            }
        }
        if(ans==-1) return ans;
        return n-ans;
    }
};