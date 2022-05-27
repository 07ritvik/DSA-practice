class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int twoSum=target-nums[i]-nums[j];
                int left=j+1;
                int right=n-1;
                while(left<right){
                    if(nums[left]+nums[right]==twoSum){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        sort(v.begin(),v.end());
                        ans.push_back(v);
                        
                        while(left<right && nums[left]==v[2]) left++;
                        while(left<right && nums[right]==v[3]) right--;
                    }
                    else if(nums[left]+nums[right]>twoSum) right--;
                    else left++;
                }
                while(j+1<n && nums[j]==nums[j+1]) j++;
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};