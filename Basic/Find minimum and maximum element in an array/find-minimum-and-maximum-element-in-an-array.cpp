//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends

long long Mina(long long a[], int n)
{
    int mini = INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(a[i]<mini)
        {
            mini = a[i];
        }
    }
    return mini;
}

long long Maxa(long long a[], int n)
{
    int maxi = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(a[i]>maxi)
        {
            maxi = a[i];
        }
    }
    return maxi;
}

pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long, long long> p;
    p.first = Mina(a, n);
    p.second = Maxa(a,n);
    return p;
    
}