// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int freq[n+1]={0},sum=0;
        int *k=new int[2];
        sort(arr,arr+n);
        for(int i=0;i<n-1;i++){
            sum+=arr[i];
            if(arr[i]==arr[i+1]) k[0]=arr[i];
        }
        sum+=arr[n-1];
        int miss=1;
        for(int i=0;i<n;i++){
            
                if(miss==arr[i]){
                    miss++;
                }
            
        }
        k[1]=miss;
        return k;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends