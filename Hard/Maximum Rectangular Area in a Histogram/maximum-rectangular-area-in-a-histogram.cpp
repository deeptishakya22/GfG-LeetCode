//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long> s;
        long long max_area = 0, cur_area = 0;
        for(int i = 0; i <= n; i++) {
            while(!s.empty() && (i == n || arr[i] <= arr[s.top()])) {
                long long tp = s.top();
                s.pop();
                cur_area = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                if(cur_area > max_area)
                    max_area = cur_area;
            }
            s.push(i);
        }
        return max_area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends