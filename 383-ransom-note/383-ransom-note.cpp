class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int> m1,m2;
        for(int i=0;i<r.size();i++){
            m1[r[i]]++;
        }
        for(int i=0;i<m.size();i++){
            m2[m[i]]++;
        }
        for(int i=0;i<r.size();i++){
            if(m1[r[i]]>m2[r[i]]) return false;
        }
        return true;
    }
};