//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int a[],int n){
        int temp[n];
        temp[0] = a[0];
        int res = 1;
        for(int i=0; i<n; i++) {
            if(temp[res-1] != a[i]) {
                temp[res] = a[i];
                res++;
            }
        }
        
        for(int i=0; i<res; i++) {
            a[i] = temp[i];
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends