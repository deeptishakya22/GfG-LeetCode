//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        long ans=0, u=0, j=-1, l=0;
        for(int i=0; i<n; i++)
        {
            if(R>=a[i] && a[i]>=L)
            {
                u++;
                j=i;
            }
            if(u>0 && R>=a[i])
            {
                ans+=(j-l);
                if(i>j)
                {
                    ans++;
                }
            }
            if(a[i]>R)
            {
                l=i+1;
                ans+=u;
                u=0;
            }
        }
        return ans+u;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends