//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    void reverse(int arr[], int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        // where d > n
        d = d % n;

        //rotate first part
        reverse(arr, 0, d - 1);

        //rotate second part
        reverse(arr, d, n - 1);

        //reverse the entire array
        reverse(arr, 0, n - 1);
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
// } Driver Code Ends