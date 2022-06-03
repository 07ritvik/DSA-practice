class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        if(n<3) return ans;
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    ans.push_back(v);
                    while(j<k&&nums[j]==v[1]) j++;
                    while(j<k&&nums[k]==v[2]) k--;
                        
                }
                else if(nums[i]+nums[j]+nums[k]>0) k--;
                else j++;
            }
            while(i+1<n&&nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};