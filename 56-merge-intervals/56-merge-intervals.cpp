class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<n;i++){
           if(intervals[i][0]<=end && intervals[i][1]>=end){
               end=intervals[i][1];
           }
            else if(intervals[i][0]>=start && intervals[i][1]<=end){
                start=start;
                end=end;
            }
            else{
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};