class Solution {
public:
    
    void solve(int i,int target,vector<int> &arr,vector<int> &v,vector<vector<int>> &ans){
        if(i==arr.size()){
            if(target==0) ans.push_back(v);
            return;
        }
        if(arr[i]<=target){
            v.push_back(arr[i]);
            solve(i,target-arr[i],arr,v,ans);
            v.pop_back();
        }
        solve(i+1,target,arr,v,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        solve(0,target,arr,v,ans);
        return ans;
    }
};