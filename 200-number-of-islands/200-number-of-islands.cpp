class Solution {
public:    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int islands=0;
        vector<int> dir={-1,0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    q.push({i,j});
                    grid[i][j]='0';
                    islands++;
                    while(!q.empty()){
                        pair<int,int> p=q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int r=p.first+dir[k],c=p.second+dir[k+1];
                            if(r<n && r>=0 && c<m && c>=0 && grid[r][c]=='1'){
                                grid[r][c]='0';
                                q.push({r,c});
                            }
                        }
                    }
                    
                }
            }
        }
        return islands;
    }
};