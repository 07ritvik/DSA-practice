class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int n=nums.size();
        // int cnt=1;
        // int ans=1;
        // if(n==0 || n==1) return n;
        // sort(nums.begin(),nums.end());
        // for(int i=1;i<n;i++){
        //     if(nums[i]-nums[i-1]==1){
        //         cnt++;
        //     }
        //     else if(nums[i]!=nums[i-1]){
        //         cnt=1;
        //     }
        //     ans=max(ans,cnt);
        // }
        // return ans;
        
  unordered_set < int > hashSet;
  for (int num: nums) {
    hashSet.insert(num);
  }

  int longestStreak = 0;

  for (int num: nums) {
    if (!hashSet.count(num - 1)) {
      int currentNum = num;
      int currentStreak = 1;

      while (hashSet.count(currentNum + 1)) {
        currentNum += 1;
        currentStreak += 1;
      }

      longestStreak = max(longestStreak, currentStreak);
    }
  }

  return longestStreak;
    }
};