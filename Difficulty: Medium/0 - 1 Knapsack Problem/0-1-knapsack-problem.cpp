//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int index = 0;
        int n = wt.size();
        vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
        return memo(W, wt, val, index, n, dp);
    }
    
    int memo(int W, vector<int>& wt, vector<int>& val, int index, int n, vector<vector<int>>& dp) {
        // base case
        if (index >= n) {
            return 0;
        }
        
        if (dp[W][index] != -1) {
            return dp[W][index];
        }
        
        // inclusion, exclusion
        int include = 0;
        if (wt[index] <= W) {
            include = val[index] + memo(W - wt[index], wt, val, index + 1, n, dp);
        }
        
        int exclude = 0 + memo(W, wt, val, index + 1, n, dp);
        
        dp[W][index] = max(include, exclude);
        
        return dp[W][index];
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends