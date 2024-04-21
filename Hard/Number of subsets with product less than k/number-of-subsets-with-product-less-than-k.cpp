//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numOfSubsets(int arr[], int n, int k) {
    vector<long long int> vect1, vect2, subset1, subset2;

    for (int i = 0; i < n; i++) {
        if (arr[i] > k)
            continue;
        if (i <= n / 2)
            vect1.push_back(arr[i]);
        else
            vect2.push_back(arr[i]);
    }

    for (int i = 0; i < (1 << vect1.size()); i++) {
        long long value = 1;
        for (int j = 0; j < vect1.size(); j++) {
            if (i & (1 << j))
                value *= vect1[j];
        }

        if (value <= k)
            subset1.push_back(value);
    }
 
    for (int i = 0; i < (1 << vect2.size()); i++) {
        long long value = 1;
        for (int j = 0; j < vect2.size(); j++) {
            if (i & (1 << j))
                value *= vect2[j];
        }
 
        if (value <= k)
            subset2.push_back(value);
    }

    sort(subset2.begin(), subset2.end());
 
    long long count = 0;
    for (int i = 0; i < subset1.size(); i++)
        count += upper_bound(subset2.begin(), subset2.end(),
                             (k / subset1[i]))
                 - subset2.begin();
 
    count--;
    return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends