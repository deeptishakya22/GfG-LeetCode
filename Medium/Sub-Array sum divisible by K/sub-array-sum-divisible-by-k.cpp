//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long subCount(long long arr[], int N, long long K)
	{
        unordered_map<int, int> mp;
        int sum = 0;
        
        mp[0] = 1;
        
        int result = 0;
        
        for(int i = 0; i<N; i++) {
            sum += arr[i];
            
            int rem = sum%K;
            
            if(rem < 0) {
                rem += K;
            }
            
            if(mp.find(rem) != mp.end()) {
                result += mp[rem];
            }
            
            mp[rem]++;
            
        }
        
        return result;
	}



};


//{ Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends