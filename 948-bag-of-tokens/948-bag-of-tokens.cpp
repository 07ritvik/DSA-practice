class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int power) {
        sort(t.begin(),t.end());
        int i=0,j=t.size()-1;
        
        int ans=0,score=0;
        while(i<=j){
            if(power>=t[i]){
                power-=t[i];
                score++;
                ans=max(ans,score);
                i++;
            }
            else{
                if(score>=1){
                    power+=t[j];
                    score--;
                    j--;
                }
                else break;
            }
        }
        return ans;
    }
};