//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    //helper functions
private:
    vector<int> prevSmaller(long long arr[], int n) {
        stack<int> st;
        vector<int> result(n, -1);
        for (int i = 0; i < n; i++) {
            long long curr = arr[i];
            while (!st.empty() && arr[st.top()] >= curr) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(i);
        }
        return result;
    }
    
    vector<int> nextSmaller(long long arr[], int n) {
        stack<int> st;
        vector<int> result(n, n);
        for (int i = n - 1; i >= 0; i--) {
            long long curr = arr[i];
            while (!st.empty() && arr[st.top()] >= curr) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(i);
        }
        return result;
    }
    
public:
    long long getMaxArea(long long arr[], int n) {
        vector<int> next = nextSmaller(arr, n);
        vector<int> prev = prevSmaller(arr, n);
        
        long long maxArea = 0;
        for (int i = 0; i < n; i++) {
            long long length = arr[i];
            long long width = next[i] - prev[i] - 1;
            long long currArea = width * length;
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends