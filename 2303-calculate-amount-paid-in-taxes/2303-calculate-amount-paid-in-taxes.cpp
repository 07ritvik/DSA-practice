class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans=0;
        if(income==0) return 0;
        int n=brackets.size();

        int prev=0;
        for(int i=0;i<n;i++){
            ans+=(min(income,brackets[i][0])-prev)*brackets[i][1]*1.0/100.0;
            if(brackets[i][0]>=income){
                break;
            }
            prev=brackets[i][0];
        }
        
        return ans;
    }
};