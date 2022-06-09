class Solution {
public:
    void solve(int ind,int target,vector<int> &arr,vector<int> &v,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i=ind;i<arr.size();i++){
            if(arr[i]>target) return;
            if(i!=ind&&arr[i]==arr[i-1]) continue;
            v.push_back(arr[i]);
            solve(i+1,target-arr[i],arr,v,ans);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        solve(0,target,arr,v,ans);
        return ans;
        
    }
};