//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size)
    {
        int res = 0, count = 1;
        for(int i=0; i<size; i++) {
            if(arr[res] == arr[i]) 
                count++;
            else count--;
            if(count==0) {
                res = i; 
                count = 1;
            }
        }
        
        count = 0;
        for(int i=0; i<size; i++) {
            if(arr[res] == arr[i]) {
                count++;
            }
        }
        if(count > size/2) 
            res = arr[res];
        else res = -1;
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends