//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        vector<int> prefixMin(n), prefixMax(n);
        vector<int> suffixMin(n), suffixMax(n);
        
        prefixMin[0] = arr[0];
        prefixMax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefixMin[i] = min(prefixMin[i - 1], arr[i]);
            prefixMax[i] = max(prefixMax[i - 1], arr[i]);
        }
        
        suffixMin[n - 1] = arr[n - 1];
        suffixMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], arr[i]);
            suffixMax[i] = max(suffixMax[i + 1], arr[i]);
        }
        
        int minDiff = INT_MAX;
        
        for (int i = 0; i <= n - k; i++) {
            int remainingMin = INT_MAX;
            int remainingMax = INT_MIN;
            
            if (i > 0) {
                remainingMin = prefixMin[i - 1];
                remainingMax = prefixMax[i - 1];
            }
            if (i + k < n) {
                remainingMin = min(remainingMin, suffixMin[i + k]);
                remainingMax = max(remainingMax, suffixMax[i + k]);
            }
            
            int currentDiff = remainingMax - remainingMin;
            minDiff = min(minDiff, currentDiff);
        }
        return minDiff;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends