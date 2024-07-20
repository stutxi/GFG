//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        long long int ans = 1;
        const int mod = 1e9 + 7;
        int n = arr.size();

        sort(arr.begin(), arr.end());

        if (n == 1) return arr[0];

        int i = 0;
        bool hasPositive = false;

        while (i < n) {
            //process negative numbers
            while (i < n && arr[i] < 0) {
                ans = (ans * arr[i]) % mod;
                i++;
            }
            //if the product so far is negative and there are negative numbers
            if (ans < 0 && i > 0 && arr[i - 1] < 0) {
                ans = (ans / arr[i - 1]) % mod;
                if (ans < 0) ans += mod;
            }
            //skip zeros
            while (i < n && arr[i] == 0) {
                i++;
            }
            //process positive numbers
            while (i < n && arr[i] > 0) {
                ans = (ans * arr[i]) % mod;
                hasPositive = true;
                i++;
            }
        }
        //if the result is negative but there are positive numbers, ensure it's positive
        if (ans < 0 && hasPositive) ans += mod;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends