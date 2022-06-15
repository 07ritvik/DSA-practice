class Solution {
public:
    unordered_map<string,bool> dp;
    bool solve(string s,unordered_map<string,bool> &mp){
        int n=s.size();
        
        if(mp.find(s)!=mp.end()) return true;
        
        if(dp.find(s)!=dp.end()) return dp[s];
        
        if(n==0) return true;
        
        for(int i=1;i<=n;i++){
            if(mp.find(s.substr(0,i))!=mp.end()){
                if(solve(s.substr(i),mp)){
                    dp[s.substr(i)]=true;
                    return true;
                }
            }
        }
        dp[s]=false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> mp;
        for(int i=0;i<wordDict.size();i++){
            mp[wordDict[i]]=true;
        }
        return solve(s,mp);
    }
};