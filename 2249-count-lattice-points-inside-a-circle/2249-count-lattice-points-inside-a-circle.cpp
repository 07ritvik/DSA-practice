class Solution {
public:
    int countLatticePoints(vector<vector<int>>& v) { // v is vector of circles.
        int n = v.size();
        set<pair<int,int>> s;
        for(int i=0;i<n;i++){
            int a=v[i][0],b=v[i][1],r=v[i][2];
            for(int x=a-r;x<=a+r;x++){
                for(int y=b-r;y<=b+r;y++){
                    if(((x-a)*(x-a))+((y-b)*(y-b))-(r*r)<=0){
                        s.insert({x,y});
                    }
                }
            }
        }
        int ans = s.size();
        return ans;
    }
};