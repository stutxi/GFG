//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int start = 0, end = n - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] < k) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        
        int closestIndex = start;
        
        if (closestIndex > 0) {
            int prevIndex = closestIndex - 1;
            if (abs(arr[prevIndex] - k) <= abs(arr[closestIndex] - k)) {
                if (abs(arr[prevIndex] - k) == abs(arr[closestIndex] - k)) {
                    closestIndex = std::max(arr[prevIndex], arr[closestIndex]) == arr[prevIndex] ? prevIndex : closestIndex;
                } else {
                    closestIndex = prevIndex;
                }
            }
        }
        return arr[closestIndex];
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends