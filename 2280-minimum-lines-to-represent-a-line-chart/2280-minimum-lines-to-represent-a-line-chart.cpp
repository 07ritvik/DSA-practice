class Solution {
public:
    int minimumLines(vector<vector<int>>& s) {
        sort(s.begin(),s.end());
        int n=s.size();
        long long ans=1;
        long long x1,x2,x3,y1,y2,y3;
        if(n==1) return 0;
        for(int i=2;i<n;i++){
            x1=s[i][0];
            x2=s[i-1][0];
            x3=s[i-2][0];
            y1=s[i][1];
            y2=s[i-1][1];
            y3=s[i-2][1];
            long diff1 = (y3-y2) * (x2-x1);
            long diff2 = (y2-y1) * (x3-x2);
            if(diff1 != diff2) ans++;
        }
        return ans;
    }
};