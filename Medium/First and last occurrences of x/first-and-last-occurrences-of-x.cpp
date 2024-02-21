//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int left = binarySearchLeft(arr, n, x);
        int right = binarySearchRight(arr, n, x);
        
        if (left <= right) {
            return {left, right};
        } else {
            return {-1, -1};
        }
    }

private:
    int binarySearchLeft(int arr[], int n, int x) {
        int start = 0, end = n - 1;
        int leftIndex = -1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] >= x) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
            if (arr[mid] == x) {
                leftIndex = mid;
            }
        }
        return leftIndex;
    }
    
    int binarySearchRight(int arr[], int n, int x) {
        int start = 0, end = n - 1;
        int rightIndex = -1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] <= x) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            if (arr[mid] == x) {
                rightIndex = mid;
            }
        }
        return rightIndex;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends