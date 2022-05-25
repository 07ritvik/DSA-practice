class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        // int i=0,j=n-1;
        // while(i>=0 && i<n &&j>=0 && j<m){
        //     if(matrix[i][j]==target) return true;
        //     else if(matrix[i][j]>target){
        //         j--;
        //     }
        //     else{
        //         i++;
        //     }
        // }
        // return false;
        int low=0,high=(m*n)-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid/m][mid%m]==target) return true;
            else if(matrix[mid/m][mid%m]<target){
                low=mid+1;
            }
            else high=mid-1;
        }
        return false;
    }
};