//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
      if(i >= n) return;
      
      int left = 2*i+1;
      int right = 2*i+2;
      int m = i;
      if(left < n && arr[left] > arr[m]) m = left;
      if(right < n && arr[right] > arr[m]) m = right;
      
      if(i != m){
          swap(arr[i],arr[m]);
        //   cout << i << " " << m << endl;
          heapify(arr,n,m);
      } 
    }
    
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        // Your Code Here
        int k = (n/2)+1;
        
        // cout << "start" << endl;
        for(int i=k; i>=0; i--){
          heapify(arr,n,i);
        }
        // cout << "end" << endl;
    }

    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        // for(int i=0; i<n; i++){
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        for(int i=n-1; i>=0; i--){
            swap(arr[i],arr[0]);
            // cout << i << ": ";
            heapify(arr,i,0);   
            // cout << endl;
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends