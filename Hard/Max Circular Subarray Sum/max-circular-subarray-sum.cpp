//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        int max_nor = normalMaxSum(arr, num);
        if(max_nor < 0) {
            return max_nor;
        }
        int arr_sum = 0;
        for(int i=0; i<num; i++) {
            arr_sum += arr[i];
            arr[i] =- arr[i];
        }
        int max_cir = arr_sum + normalMaxSum(arr,num);
        return max(max_nor, max_cir);
    }
    
    int normalMaxSum(int arr[], int num) {
        int res = arr[0];
        int maxEnd = arr[0];
        for(int i=1; i<num; i++) {
            maxEnd = max(maxEnd + arr[i], arr[i]);
            res = max(res, maxEnd);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends