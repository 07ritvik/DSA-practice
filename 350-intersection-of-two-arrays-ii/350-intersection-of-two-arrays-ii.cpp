class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         map<int,int> mp1,mp2;
//         for(auto i:nums1) mp1[i]++;
//         for(auto i:nums2) mp2[i]++;
        
//         vector<int> ans;
        
//         for(auto it:mp1){
//             int num=it.first,cnt=it.second;
//             if(mp2.find(num)!=mp2.end()){
//                 cnt=min(cnt,mp2[num]);
//                 while(cnt--){
//                     ans.push_back(num);
//                 }
//             }
//         }
//         return ans;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    
    int n=nums1.size();
    int m=nums2.size();
    vector<int> ans;
    
    int i=0,j=0;
    
    
    while(i<n && j<m)
    {
        if(nums1[i]>nums2[j])
            j++;
        else if(nums2[j]>nums1[i])
            i++;
        else
        {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
            
    }
    
    return ans;
    }
};