// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        // Your code here
        // vector<int> v(n);
        // for(int i=0;i<n;i++){
        //     v[i]=arr[i];
        // }
        // for(int i=0;i<n/2;i++){
        //     int idx=-1;
        //     for(int j=i+1;j<k;j++){
        //         if(v[i]>v[j]){
        //             idx=min(idx,j);
        //         }
        //     }
        //     if(idx!=-1){
        //         swap(v[i],v[idx]);
        //     }
        // }
        
        // return v;
        
        priority_queue<int,vector<int>,greater<int>> minh;
        vector<int> ans;
        for(int i=0;i<n;i++){
            minh.push(arr[i]);
            if(minh.size()>k){
                ans.push_back(minh.top());
                minh.pop();
            }
        }
        while(!minh.empty()){
            ans.push_back(minh.top());
            minh.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends