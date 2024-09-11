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
        int ans = solve(W, wt, val, index, n);
        return ans;
    }
    
    // recursion
    int solve(int W, vector<int>& wt, vector<int>& val, int index, int n) {
        // base case
        if (index == n - 1) {
            if (wt[index] <= W) {
                return val[index];
            } else {
                return 0;
            }
        }
        
        // inclusion, exclusion
        int include = 0;
        if (wt[index] <= W) {
            include = val[index] + solve(W - wt[index], wt, val, index + 1, n);
        }
        
        int exclude = 0 + solve(W, wt, val, index + 1, n);
        
        int ans = max(include, exclude);
        
        return ans;
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