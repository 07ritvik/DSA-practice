class Solution {
public:
    unordered_map<int,int> mp;
    void solve(int num,int n,int cnt,int k,vector<int> &ans){
        
        if(cnt==n){
            if(mp.find(num)==mp.end()){
                ans.push_back(num);
                mp[num]++;
            }
            return;
        }
        int temp=num%10;
        if(temp+k<=9){
            solve(num*10+(temp+k),n,cnt+1,k,ans);
        }
        if(temp-k>=0){
            solve(num*10+(temp-k),n,cnt+1,k,ans);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            solve(i,n,1,k,ans);
        }
        return ans;
    }
};