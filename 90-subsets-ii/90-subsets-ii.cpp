class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    v.push_back(nums[j]);
                }
            }
            sort(v.begin(),v.end());
            s.insert(v);
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
        
    }
};