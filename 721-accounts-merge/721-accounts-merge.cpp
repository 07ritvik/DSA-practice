class Solution {
    unordered_map<string,vector<string>> adj;
    unordered_set<string> seen;
    vector<vector<string>> ans;
public:
    void dfs(string &email){
        seen.insert(email);
        ans.back().push_back(email);
        
        for(auto &it:adj[email]){
            if(!seen.count(it)){
                dfs(it);
            }
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto &it:accounts){
            for(int i=2;i<it.size();i++){
                adj[it[i]].push_back(it[i-1]);
                adj[it[i-1]].push_back(it[i]);
            }
        }
        for(auto& it: accounts){
            if(!seen.count(it[1])){
                ans.push_back({it[0]});
                dfs(it[1]);
                sort(begin(ans.back())+1,end(ans.back()));
            }
        }
        return ans;
    }
};