class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans=0;
        int i=0,j=0;
        while(j<s.length()){
            mp[s[j]]++;
            if(mp.size()==j-i+1){
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};