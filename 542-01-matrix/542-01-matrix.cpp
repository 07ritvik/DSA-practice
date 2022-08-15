class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else mat[i][j]=-1;
                
            }
        }
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            pair<int,int> front=q.front();
            q.pop();
            int x=front.first,y=front.second;
            for(int i=0;i<4;i++){
                int x1=x+dir[i][0];
                int y1=y+dir[i][1];
                
                if(x1>=0 && x1<n &&y1>=0 &&y1<m &&mat[x1][y1]==-1){
                    mat[x1][y1]=mat[x][y]+1;
                    q.push({x1,y1});
                }
            }
        }
        return mat;
    }
};