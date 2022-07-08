class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0],left=0,right=0;
        
        for(int i=0;i<n;i++){
           left=(left==0?1:left)*nums[i];
           right=(right==0?1:right)*nums[n-1-i]; 
            ans=max(ans,max(left,right));
        }
        return ans;
    }
};