class Solution {
public:
bool checkPalindrome(string ns){
    int i=0;
    int j=ns.size()-1;
    
    while(i<j){
        if(ns[i]!=ns[j]){
            return false;
        }
        i++;
        j--;
    }
    
    return true;
}

bool isPalindrome(string s) {
    int n = s.size();
    string newString="";
    for(int i=0; i<n; i++){
        if(s[i]>='A' && s[i]<='Z'){
            newString+=(char)tolower(s[i]);
        }
        else if(s[i]>='a' && s[i]<='z'){
            newString+=s[i];
        }
        else if(s[i]>='0' && s[i]<='9'){ //just stupid edge case (OKAY, given alphanumeric)
            newString+=s[i];
        }
    }
            
    return checkPalindrome(newString);
}
    
};