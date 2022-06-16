class Solution {
public:
    int distributeCandies(vector<int>& c) {
        set<int> s;
        for(int i=0;i<c.size();i++){
            s.insert(c[i]);
        }
        if(s.size()>=c.size()/2) return c.size()/2;
        return s.size();
    }
};