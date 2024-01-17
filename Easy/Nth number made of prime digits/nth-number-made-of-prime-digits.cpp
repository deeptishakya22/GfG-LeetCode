//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    int primeDigits(int n)
    {
	    n--;
	    int ans[1000]={0};
	
	    memset(ans,0,sizeof(ans));
	
	    int i, j, digits=0, Count=0, k=0, a[4]={2,3,5,7};
        ans[0]=2;
        ans[1]=3;
        ans[2]=5;
        ans[3]=7;
        k=4;
    
        for(i=22; i<2300; i++)
        {
            int p=i;
            digits=0;
            Count=0;
            while(p)
            {
                digits++;
                int r=p%10;
                p=p/10;
                
                for(j=0;j<4;j++)
                {
                    if(r==a[j])
                    {
                        Count++;
                        break;
                    }
                }
            }
            
            if(Count==digits)
                ans[k++]=i;
            else
                continue;
        }
	    return ans[n];
    }
	
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    // All the above tasks are preprocessing, now you can run testcases
    // and then print the values accordingly
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout << ob.primeDigits(n) << "\n";   
    }
}

// } Driver Code Ends