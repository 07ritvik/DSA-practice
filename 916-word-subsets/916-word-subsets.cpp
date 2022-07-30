class Solution {
public:
    vector<int> counter(string s){
        vector<int> temp(26);
        for(auto &i:s){
            temp[i-'a']++;
        }
        return temp;
    }
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        vector<int> res(26),temp(26);
        vector<string> ans;
        int i;
        for(auto &it:w2){
            temp=counter(it);
            for(i=0;i<26;i++){
                res[i]=max(res[i],temp[i]);
            }
        }
        
        for(auto &it:w1){
            temp=counter(it);
            for(i=0;i<26;i++){
                if(temp[i]<res[i]) break;
            }
            if(i==26) ans.push_back(it);
            
        }
        return ans;
    }
};