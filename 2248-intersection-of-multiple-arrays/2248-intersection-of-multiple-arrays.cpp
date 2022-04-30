class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            vector<int> t=nums[i];
            for(int j=0;j<t.size();j++){
                mp[t[j]]++;
            }
            
        }
        for(auto it: mp){
            if(it.second==n) ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};