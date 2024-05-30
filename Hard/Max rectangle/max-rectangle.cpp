//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int getMax(int arr[], int n) {
        stack<int> s;
        int curr = 0, maxa = 0;
        for(int i=0; i<=n; i++) {
            while(!s.empty() && (i==n || arr[i]<=arr[s.top()])) {
                int tp = s.top();
                s.pop();
                curr = arr[tp] * (s.empty() ? i : i-s.top()-1);
                maxa =  max(curr, maxa);
            }
            s.push(i);
        }
        return maxa;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        int res = getMax(M[0], m);
        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(M[i][j] == 1)
                    M[i][j] += M[i-1][j];
            }
            res = max(res, getMax(M[i], m));
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends