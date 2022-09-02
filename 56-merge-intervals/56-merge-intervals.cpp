class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        vector<int> interval;
        interval=intervals[0];
        
        for(auto it:intervals){
            if(it[0]>interval[1]){
                
                ans.push_back(interval);
                interval=it;
            }
            else{
                interval[1]=max(it[1],interval[1]);
            }
        }
        ans.push_back(interval);
        return ans;
    }
};