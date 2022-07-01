class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(),b.end(),cmp);
        int ans=0;
        for(int i=0;i<b.size()&&t>0;i++){
            if(b[i][0]<=t){
                t-=b[i][0];
                ans+=b[i][0]*b[i][1];
            }
            else{
                ans+=t*b[i][1];
                t=0;
            }
        }
        return ans;
    }
};