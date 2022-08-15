class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
        for(int i=0;i<p.size();i++){
            int u=p[i][0],v=p[i][1];
            adj[v].push_back(u);
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i); 
        }
        int ans=0;
        
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            ans++;
            for(auto it:adj[temp]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(ans==n) return true;
        return false;
    }
};