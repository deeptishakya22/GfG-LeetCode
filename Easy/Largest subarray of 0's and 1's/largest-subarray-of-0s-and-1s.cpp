//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int n)
    {
        unordered_map<int, int> m;
        int sum = 0;
        int max_len = 0; 
        int ending_index = -1;
 
        for (int i = 0; i < n; i++)
            arr[i] = (arr[i] == 0) ? -1 : 1;
 
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == 0) {
                max_len = i + 1;
                ending_index = i;
            }
 
            if (m.find(sum) != m.end()) {
                if (max_len < i - m[sum]) {
                    max_len = i - m[sum];
                    ending_index = i;
                }
            }
            else // Else put this sum in hash table
                m[sum] = i;
        }
 
        for (int i = 0; i < n; i++)
            arr[i] = (arr[i] == -1) ? 0 : 1;
 
        return max_len;
    }
};


//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends