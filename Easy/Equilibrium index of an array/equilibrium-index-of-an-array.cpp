//{ Driver Code Starts
#include <iostream>
using namespace std;
#include <stdio.h>
 
int findEquilibrium(int [], int );
 
int main() {
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<findEquilibrium (a,n)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends


/* You are required to complete this method*/
int findEquilibrium(int a[], int n)
{
        long long sum = 0;
        for(int i=0; i<n; i++) {
            sum += a[i];
        }
        long long l_sum = 0;
        for(int i=0; i<n; i++) {
            if(l_sum == sum - a[i]) {
                return i;
            }
            l_sum += a[i];
            sum -= a[i];
        }
        return -1;
}