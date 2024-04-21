//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        pair<int, int> ans;
        vector<int> index(k, 0);
        set<pair<int, int>> Set;
        for(int i = 0; i < k; i++) {
            Set.insert({KSortedArray[i][0], i});
        }
        int minLen = INT_MAX;
        while(true) {
            pair<int, int> temp = *Set.begin();
            int Min = temp.first;
            int Max = (*(--Set.end())).first;
            int len = Max - Min + 1;
            if(len < minLen) {
                ans.first = Min;
                ans.second = Max;
                minLen = len;
            }
            Set.erase(Set.begin());
            index[temp.second]++;
            if(index[temp.second] < n)
            Set.insert({KSortedArray[temp.second][index[temp.second]], temp.second});
            else
            break;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends