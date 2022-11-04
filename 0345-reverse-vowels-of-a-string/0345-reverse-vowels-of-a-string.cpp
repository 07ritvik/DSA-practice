class Solution {
public:
    string reverseVowels(string s) {
        string vowel="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u' || s[i]=='A' || s[i]=='E'|| s[i]=='I'|| s[i]=='O'|| s[i]=='U'){
                vowel+=s[i];
            }
        }
        int i=0,j=vowel.size()-1;
        while(j>=0){
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u' || s[i]=='A' || s[i]=='E'|| s[i]=='I'|| s[i]=='O'|| s[i]=='U'){
                s[i]=vowel[j];
                j--;
            }
            i++;
        }
        return s;
        
    }
};