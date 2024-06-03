//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        // code here
        const int mod = 1000000007;
        
        if (n == 1) {
            return 0;
        }

        vector<long long> dp(n + 1, 0);
        dp[1] = 2;
        dp[2] = 3;

        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }

        long long totalStrings = 1;
        for (int i = 0; i < n; i++) {
            totalStrings = (totalStrings * 2) % mod;
        }

        long long ans = (totalStrings - dp[n] + mod) % mod;

        return (int)ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends