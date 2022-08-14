class Solution {
public:
    // int val;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
       int val=image[sr][sc];
        if(image[sr][sc]==color)
        {
           return image; 
        }
        dfs(image,val,sr,sc,color);
        return image;
    }
    void dfs(vector<vector<int>>&arr,int val,int row,int col,int &color)
    {
        if(row<0 or row>=arr.size() or col<0 or col>=arr[0].size())
        {
            return;
        }
        if(arr[row][col]!=val)
        {
            return;
        }
        
        if(arr[row][col]==val)
        arr[row][col]=color;
        
        dfs(arr,val,row+1,col,color);  //down
        dfs(arr,val,row-1,col,color);  //up
        dfs(arr,val,row,col-1,color);  //left
        dfs(arr,val,row,col+1,color);  //right
    }
};