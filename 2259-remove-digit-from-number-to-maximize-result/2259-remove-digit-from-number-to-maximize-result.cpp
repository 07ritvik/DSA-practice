class Solution {
public:
    string removeDigit(string s, char d) {
//         string ans;
//         priority_queue<string> maxh;
//         for(int i=0;i<s.length();i++){
//             string t;
//             if(s[i]==d){
//                 t=s.substr(0,i)+s.substr(i+1,s.length()-i-1);
             
//                maxh.push(t);
//             }
//         }
//         ans=(maxh.top());
//         return ans;
        
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==d){
                if(s[i+1]>s[i]){
                    return s.substr(0,i)+s.substr(i+1,s.length()-i-1);
                }
            }
        }
        int idx=s.find_last_of(d);
        return s.substr(0,idx)+s.substr(idx+1,s.length()-idx-1);
    }
};