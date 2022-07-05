class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0||n==1) return n;
        vector<int> v(n,1);
        v[0]=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1){
                v[i]=v[i-1]+v[i];
            }
            else if(nums[i]==nums[i-1]) v[i]=v[i-1];
            
        }
        return *max_element(v.begin(),v.end());
    }
};