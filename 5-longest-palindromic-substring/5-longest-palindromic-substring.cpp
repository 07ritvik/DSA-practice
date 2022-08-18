class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0 || n==1) return s;
        int l=1;
        string str="";
        str+=s[0];
        for(int i=0;i<n;i++){
            int x=i-1, y =i+1;
            while(x>=0 && s[x]==s[i]) x--;
            while(y<n && s[y]==s[i]) y++;
            while(x>=0 && y<n && s[x]==s[y])
            {
                x--;
                y++;
            }
            if(l<y-x-1){
                l=y-x-1;
                str=s.substr(x+1,l);
            }
            
            
        }
        return str;
    }
};