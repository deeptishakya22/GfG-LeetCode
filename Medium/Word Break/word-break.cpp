//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    bool can(int i, string& A, vector<string> & B){
        if(i == A.size())
            return true;
            
        for(auto str: B){
            if(str.size() <= (A.size() - i) && A.substr(i, str.size()) == str){
                if(can(i + str.size(), A, B))
                    return true;
            }
        }
        
        return false;
    }
    
    int wordBreak(int n, string s, vector<string> &dictionary) {
       return can(0,s,dictionary);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends