class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // unordered_map<int,int> mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        //     if(mp[nums[i]]>1) return nums[i];
        // }
        int slow=nums[0],fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
       
    }
};