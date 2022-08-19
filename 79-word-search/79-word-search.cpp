// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int m=board.size(),n=board[0].size();
//         vector<vector<bool>> vis(m,vector<bool>(n,false));
        
//         queue<pair<int,int>> q;
//         int ind=0;
//         vector<int> dir={1,0,-1,0,1};
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                  ind=0;
//                 if(board[i][j]==word[ind] && !vis[i][j]){
//                     ind++;
//                     q.push({i,j});
//                     vis[i][j]=true;
//                     while(!q.empty()){
//                         pair<int,int> p=q.front();
//                         q.pop();
                        
//                         for(int k=0;k<4;k++){
//                             int r=p.first+dir[k],c=p.second+dir[k+1];
//                             if(r>=0 && r<m && c>=0 && c<n && board[r][c]==word[ind] && vis[r][c]==false){
//                                 cout<<ind<<" ";
//                                 ind++;
//                                 q.push({r,c});
//                                 vis[r][c]=true;
//                                 if(ind==word.size()) return true;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         if(ind==word.size()) return true;
//         return false;
//     }
// };

class Solution {
public:
        bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int index)
    {
        if(index == word.size()) return true; // end condition
        if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1) return false; // boundary of matrix
        if(board[i][j] != word[index]) return false; // do not match
        // match!
        board[i][j] = '*'; // change the content, to avoid duplicated search
        bool furtherSearch =  dfs(board, word, i+1, j, index+1) || // up
                              dfs(board, word, i-1, j, index+1) || // down
                              dfs(board, word, i, j-1, index+1) || // left
                              dfs(board, word, i, j+1, index+1);   // right
        
        board[i][j] = word[index]; // modify it back!
        return furtherSearch;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    
    }


};