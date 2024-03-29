class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> indegree(n),ans;
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==1) q.push(i);
        }
        
        while(!q.empty()){
            int size=q.size();
            ans.clear();
            for(int i=0;i<size;i++){
                int curr=q.front();
                q.pop();
                ans.push_back(curr);
                for(auto it:g[curr]){
                    indegree[it]--;
                    if(indegree[it]==1) q.push(it);
                }
            }
        }
        if(n==1) ans.push_back(0);
        return ans;
    }
};