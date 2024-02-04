//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int maxWater(int arr[], int n) {
        int res = 0;
        int lmax[n], rmax[n];
        lmax[0] = arr[0];
        for(int i=1; i<n; i++) {
            lmax[i] = max(arr[i], lmax[i-1]);
        }
        
        rmax[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--) {
            rmax[i] = max(arr[i], rmax[i+1]);
        }
        
        for(int i=1; i<n-1; i++) {
            res = res + (min(lmax[i], rmax[i]) - arr[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxWater(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends