//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    const int CHAR = 256;
    int areAnagram(string S1, string S2) {
        if(S1.length() != S2.length())
            return 0;
        int count[CHAR] = {0};
        for(int i=0; i<S1.length(); i++) {
            count[S1[i]]++;
            count[S2[i]]--;
        }
        for(int i=0; i<CHAR; i++) {
            if(count[i] != 0)
                return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1, S2;
        cin >> S1;
        cin >> S2;
        Solution ob;
        cout << ob.areAnagram(S1, S2) << endl;
    }
    return 0;
}

// } Driver Code Ends