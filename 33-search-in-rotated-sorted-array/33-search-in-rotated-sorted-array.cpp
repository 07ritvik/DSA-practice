class Solution {
public:
    // int BS(vector<int>&nums,int low,int high,int target){
    //     while(low<=high){
    //         int mid=low+(high-low)/2;
    //         if(nums[mid]==target) return mid;
    //         if(nums[mid]<target) low=mid+1;
    //         else high=mid-1;
    //     }
    //     return -1;
    // }
    // int minInd(vector<int>&nums,int low,int high){
    //     int n=nums.size();
    //     while(low<=high){
    //         if(nums[low]<=nums[high]) return low;
    //         int mid=low+(high-low)/2;
    //         int prev=(mid-1+n)%n;
    //         int next=(mid+1)%n;
    //         if(nums[mid]<=nums[prev]&&nums[mid]<=nums[next]) return mid;
    //         else if(nums[low]<=nums[mid]) low=mid+1;
    //         else high=mid-1;
    //     }
    //     return -1;
    // }
    // int search(vector<int>& nums, int target) {
    //     int ind=minInd(nums,0,nums.size()-1);
    //     int a=BS(nums,0,ind-1,target);
    //     int b=BS(nums,ind,nums.size()-1,target);
    //     if(a!=-1) return a;
    //     return b;
    // }
int search(vector < int > & nums, int target) {
  int low = 0, high = nums.size() - 1; //<---step 1

  while (low <= high) { //<--- step 2
    int mid = (low + high) >> 1; //<----step 3
    if (nums[mid] == target)
      return mid; // <---step 4

    if (nums[low] <= nums[mid]) { //<---step 5
      if (nums[low] <= target && nums[mid] >= target)
        high = mid - 1; //<---step 6 
      else
        low = mid + 1; //<---step 7
    } else { //<---step 7
      if (nums[mid] <= target && target <= nums[high])
        low = mid + 1;
      else
        high = mid - 1;
    }
  }
  return -1; //<---step 8
}    
};