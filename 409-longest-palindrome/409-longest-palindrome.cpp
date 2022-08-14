class Solution {
public:

    int longestPalindrome(string s) {
        if(s=="") return 0;
        if(s.size()==1) return 1;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        int ans=0;
        for(auto i:mp){
            if(i.second>=2 && i.second%2==0){
                ans+=i.second;
                i.second=0;
            }
            if(i.second>=2&& i.second%2!=0){
                ans+=i.second -1;
                i.second=1;
            }
        }
        if(ans==s.size()) return ans;
        return ans+1;

    }
};