//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dx[3] = { -1, 0, 1 };
    int dy[3] = { -1, -1, -1 };
 
    bool isValid(int x, int y, int n, int m)
    {
        if (x >= 0 && x < n && y >= 0 && y < m)
            return true;
        return false;
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int dp[n][m];
        for (int i = 0; i < n; i++)
            dp[i][0] = M[i][0];
 
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int mx = INT_MIN;
                for (int k = 0; k < 3; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
 
                    if (isValid(x, y, n, m))
                        mx = max(mx, dp[x][y] + M[i][j]);
                }
                dp[i][j] = mx;
            }
        }
 
        int ans = INT_MIN;
    
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i][m - 1]);
        }
        return ans;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends