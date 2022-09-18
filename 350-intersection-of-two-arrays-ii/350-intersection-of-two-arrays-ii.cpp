class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1,mp2;
        for(auto i:nums1) mp1[i]++;
        for(auto i:nums2) mp2[i]++;
        
        vector<int> ans;
        
        for(auto it:mp1){
            int num=it.first,cnt=it.second;
            if(mp2.find(num)!=mp2.end()){
                cnt=min(cnt,mp2[num]);
                while(cnt--){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};