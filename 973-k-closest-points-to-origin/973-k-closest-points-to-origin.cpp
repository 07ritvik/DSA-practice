class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> minh;
        priority_queue<pair<int,vector<int>>> maxh;
        for(auto i:points){
            int d=pow(i[0],2)+pow(i[1],2);
            maxh.push({d,i});
            
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        vector<vector<int>> ans;
        while(!maxh.empty()){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        return ans;
    }
};