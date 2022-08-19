class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),m=p.size();
        vector<int> ans;
        if(n<m) return ans;
        unordered_map<char,int> mp;
        for(int i=0;i<m;i++){
            mp[p[i]]++;
        }
        int i=0,j=0;
        int cnt=mp.size();
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    cnt--;
                }
            }
            if(j-i+1<m) j++;
            
            else if(j-i+1==m){
                if(cnt==0) ans.push_back(i);
                
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1) cnt++;
                }
                i++;j++;
            }
        }
        return ans;
    }
};