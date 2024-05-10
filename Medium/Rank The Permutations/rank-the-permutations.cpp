//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long fact(int n) { 
        return (n <= 1) ? 1 : n * fact(n - 1); 
    }
 
    int findSmallerInRight(string str, int low, int high)
    {
        int countRight = 0, i;
 
        for (i = low + 1; i <= high; ++i)
            if (str[i] < str[low])
                ++countRight;
 
        return countRight;
    }
    
    long long findRank(string str) {
        int len = str.size();
        long long mul = fact(len);
        long long rank = 1;
        int countRight;
 
        int i;
        for (i = 0; i < len; ++i) {
            mul /= len - i;
            countRight = findSmallerInRight(str, i, len - 1);
            rank += countRight * mul;
        }
        return rank;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends