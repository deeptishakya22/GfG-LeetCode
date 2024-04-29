//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
	vector <string> v;
	void per(string s,int l,int r)
	{
	    if(l==r)
	        v.push_back(s);
	    else {
            for(int i=l;i<r;i++)
	        {
	            swap(s[l],s[i]);
	            per(s,l+1,r);
	            swap(s[l],s[i]);
	        }
	    }
	}
	
    vector<string> permutation(string S)
    {
		int r=S.length();
	    per(S,0,r);
	    sort(v.begin(),v.end());
	    return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends