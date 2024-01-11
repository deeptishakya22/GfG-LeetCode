//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    typedef long long int ll;
    long long int count(int coins[], int N, int sum) {
        vector<vector<ll>> dp(N+1,vector<ll> (sum+1));
        for(ll i=0;i<=N;i++)
          dp[i][0]=1;
        for(ll i=1;i<=sum;i++)
          dp[0][i]=0;
        for(ll  i=1;i<=N;i++)
        {
            for(ll j=1;j<=sum;j++)
            {
                if(coins[i-1]<=j)
                  dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                else
                  dp[i][j]=dp[i-1][j];
            }
        }
        return dp[N][sum];

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends