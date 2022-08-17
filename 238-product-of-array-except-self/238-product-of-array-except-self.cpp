class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int pre=1,suff=1;
        for(int i=0;i<nums.size();i++){
            ans[i]*=pre;
            pre*=nums[i];
            ans[nums.size()-1-i]*=suff;
            suff*=nums[nums.size()-1-i];
        }
        return ans;
    }
};