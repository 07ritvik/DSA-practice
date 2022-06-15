class Solution {
public:
    int solve(string a,string b){
        int n=a.size();
        int m=b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0) dp[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),compare);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(words[i].length()-words[j].length()==1 && solve(words[i],words[j])==words[j].length()){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};