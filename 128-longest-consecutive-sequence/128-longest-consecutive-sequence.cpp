class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        int ans=1;
        if(n==0 || n==1) return n;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]==1){
                cnt++;
            }
            else if(nums[i]!=nums[i-1]){
                cnt=1;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};