//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low<high) {
            int pi = partition(arr,low,high);
            quickSort(arr,low,pi-1);
            quickSort(arr,pi+1,high);
        }
    }
    
    public:
    int partition (int a[], int start, int end)
    {
        int pivot = a[end];  
        int i = (start - 1);  
  
        for (int j = start; j <= end - 1; j++)  
        {   
            if (a[j] < pivot)  
            {  
                i++;  
                int t = a[i];  
                a[i] = a[j];  
                a[j] = t;  
            }  
        }  
        int t = a[i+1];  
        a[i+1] = a[end];  
        a[end] = t;  
        return (i + 1); 
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends