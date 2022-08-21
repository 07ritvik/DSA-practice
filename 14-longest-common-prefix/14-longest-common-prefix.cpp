class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string a=strs[0];
        string ans="";
        for(int i=1;i<strs.size();i++){
            string b=strs[i];
            int j=0,k=0;
            while(j<a.size()&&k<b.size()){
                if(a[j]==b[k]){
                   ans+=a[j]; 
                    j++;k++;
                   
                }
                else break;
            }
            a=ans;
            ans="";
            
        }
        return a;
    }
};