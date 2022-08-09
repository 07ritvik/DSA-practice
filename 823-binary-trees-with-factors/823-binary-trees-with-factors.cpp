class Solution {
public:
//     long long mod=1e9+7;
//     unordered_map<int,int> mp,dp;
    
//     long long solve(vector<int>& arr,int x){
//         if(dp.find(x)!=dp.end()) return dp[x];
//         int n=arr.size();
//         long long res=1;    
//         for(int i=0;i<n;i++){
//             if(x%arr[i]==0 && mp.find(x/arr[i])!=mp.end()){
//                 res+=(solve(arr,arr[i])%mod*solve(arr,x/arr[i])%mod)%mod;
//             }
//         }
//         return dp[x]=res;
        
//     }
//     int numFactoredBinaryTrees(vector<int>& arr) {
//         int n=arr.size();
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             mp[arr[i]]++;
//         }
//         for(int i=0;i<n;i++){
//             cnt+=solve(arr,arr[i])%mod;
//         }
//         return cnt%mod;
//     }

    int numFactoredBinaryTrees(vector<int>& A) {
        long res = 0, mod = pow(10, 9) + 7;
        sort(A.begin(), A.end());
        unordered_map<int, long> dp;
        for (int i = 0; i < A.size(); ++i) {
            dp[A[i]] = 1;
            for (int j = 0; j < i; ++j)
                if (A[i] % A[j] == 0)
                    dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % mod;
            res = (res + dp[A[i]]) % mod;
        }
        return res;
    }    
};