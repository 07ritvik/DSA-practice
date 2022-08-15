class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<int> tomerge=newInterval;
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            vector<int> temp=intervals[i];
            if(temp[0]>tomerge[1] || temp[1]<tomerge[0]){
                if(temp[0]>tomerge[1]){
                    ans.push_back(tomerge);
                    tomerge=temp;
                }
                else ans.push_back(temp);
            }
            else{
                tomerge={min(temp[0],tomerge[0]),max(tomerge[1],temp[1])};
            }
        }
        ans.push_back(tomerge);
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        //         vector<int> start;
//         for(int i=0;i<intervals.size();i++){
//             start.push_back(intervals[i][0]);
//         }
//         int ind=upper_bound(start.begin(),start.end(),newInterval[0])-start.begin();
//         vector<vector<int>> ans;
//         for(int i=0;i<intervals.size();i++){
//             if(i==ind) {
//                 ans.push_back(newInterval);
//                 i--;   
//             }
//             ans.push_back(intervals[i]);
//         }
//         vector<int> t=ans[0];
//         vector<vector<int>> res;
//         for(int i=1;i<ans.size();i++){
//             if(ans[i][0]<t[1]){
//                 t[1]=max(ans[i][1],t[1]);
                
//             } 
//             res.push_back(t);
//         }
//         res.push_back(t);
        
//         return res;
        
        
        
    }
};


// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& ino, vector<int>& newInterval) {
//         vector<int> toMerge = newInterval;
//         vector<vector<int>> ans;
//         for(int i=0;i<ino.size();i++){
//             vector<int> temp = ino[i];
//             if(temp[0]>toMerge[1] or temp[1]<toMerge[0]){
//                 if(temp[0]>toMerge[1]){
//                     ans.push_back(toMerge);
//                     toMerge = temp;
//                 }
//                 else{
//                     ans.push_back(temp);
//                 }
//             }
//             else{
//                 toMerge = {min(temp[0],toMerge[0]),max(temp[1],toMerge[1])};
//             }
//         }
//         ans.push_back(toMerge);
//         return ans;
//     }
// };