class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                ans.push_back(nums[i]);
                break;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum^=nums[i]^(i+1);
            
        }
        
        ans.push_back(sum^ans[0]);
        
        return ans;
    }
};