//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        if(K >= S.size()) return "0";
        
        stack<int> stk;
        
        for(int i = 0; i < S.size(); i++){
            while(K > 0 && !stk.empty() && stk.top() > S[i]){
                stk.pop(); 
                K--;
            }
            
            stk.push(S[i]);
        }
        
        while(K-- > 0){
            stk.pop();
        }
        
        string ans = "";
        
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        
        std::reverse(ans.begin(), ans.end());

        while(ans.size() > 1 && ans[0] == '0'){
            ans.erase(0, 1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends