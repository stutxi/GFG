//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        vector<vector<int>> neighbors = {
            {0, 8},      // 0
            {1, 2, 4},   // 1
            {2, 1, 3, 5}, // 2
            {3, 2, 6},   // 3
            {4, 1, 5, 7}, // 4
            {5, 2, 4, 6, 8}, // 5
            {6, 3, 5, 9}, // 6
            {7, 4, 8},   // 7
            {8, 5, 7, 9, 0}, // 8
            {9, 6, 8}    // 9
        };
        
        vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
        
        // base case: for length 1, each digit has one sequence
        for (int digit = 0; digit < 10; ++digit) {
            dp[1][digit] = 1;
        }
        
        // fill dp array for lengths from 2 to n
        for (int length = 2; length <= n; length++) {
            for (int digit = 0; digit < 10; digit++) {
                dp[length][digit] = 0;
                for (int prev : neighbors[digit]) {
                    dp[length][digit] += dp[length - 1][prev];
                }
            }
        }
        
        long long ans = 0;
        for (int digit = 0; digit < 10; digit++) {
            ans += dp[n][digit];
        }
        
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

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends