//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        if(s==0){
            for(int i=0;i<n;i++){
                if(arr[i]==0)return {i+1,i+1};
            }
            return {-1};
        }
        long long ans=0;
        int l=0;
        for(int r=0;r<n;r++){
            ans+=arr[r];
            while(ans>s){
                ans-=arr[l];
                l++;
            }
            if(ans==s){
                return {l+1,r+1};
            }
        }
        return {-1};

    }
};


//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends