class Solution {
public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         // vector<int> ans;
//         // for(int i=0;i<nums.size();i++){
//         //     for(int j=i+1;j<nums.size();j++){
//         //         if(nums[i]+nums[j]==target){
//         //             ans.push_back(i);
//         //             ans.push_back(j);
//         //             break;
//         //         }
//         //     }
//         // }
//         // return ans;
        
//         vector<int> temp;
//         vector<int> ans;
//         temp=nums;
//         sort(temp.begin(),temp.end());
//         int i=0,j=nums.size()-1,n1,n2;
//         while(i<=j){
//             if(temp[i]+temp[j]==target){
//                 n1=temp[i];n2=temp[j];
//                 break;
//             }
//             else if(temp[i]+temp[j]>target) j--;
//             else i++;
//         }
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==n1) ans.push_back(i);
//             else if(nums[i]==n2) ans.push_back(i);
//         }
//         return ans;
        
//     }
    vector<int> twoSum(vector<int>& nums, int target) {

    vector<int> res;
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); ++i) {

   	 if (mp.find(target - nums[i]) != mp.end()) {

   		 res.push_back(i);
   		 res.push_back(mp[target - nums[i]]);
   		 return res;
   	 }

   	 mp[nums[i]] = i;
    }

    return res;
}
};