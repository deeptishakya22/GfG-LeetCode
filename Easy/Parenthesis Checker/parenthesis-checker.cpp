//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> temp;
        for (int i = 0; i < x.length(); i++) {
            if (temp.empty()) {
             
            // If the stack is empty 
            // just push the current bracket
                temp.push(x[i]);
            }
            else if ((temp.top() == '(' && x[i] == ')')
                     || (temp.top() == '{' && x[i] == '}')
                     || (temp.top() == '[' && x[i] == ']')) {
             
            // If we found any complete pair of bracket
            // then pop
                temp.pop();
            }
            else {
                temp.push(x[i]);
            }
        }
        if (temp.empty()) {
         
        // If stack is empty return true
            return true;
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends