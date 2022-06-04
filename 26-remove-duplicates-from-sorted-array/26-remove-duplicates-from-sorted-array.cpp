class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=1;
        int n=nums.size();
        if(n==0||n==1) return n;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                nums.erase(nums.begin()+i);
                i--;
            }
            else cnt++;
        }
        return cnt;
    }
};