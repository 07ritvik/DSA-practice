class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int m=matrix.size();
        int n=matrix[0].size();
        ans=matrix;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<m;k++){
                        for(int l=0;l<n;l++){
                            if(k==i || l==j) ans[k][l]=0;
                        }
                    }
                }
            }
        }
            matrix=ans;
    }
};