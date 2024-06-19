//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long gcd(long long a, long long b) {
        if (b == 0)
            return abs(a);
        return gcd(b, a % b);
    }

    long long InternalCount(long long p[], long long q[], long long r[]) {
        // Calculate the area of the triangle using the determinant method
        long long A2 = abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1]));
        long long A = A2 / 2;

        // Calculate the number of boundary points using the gcd method
        long long B = gcd(abs(p[0] - q[0]), abs(p[1] - q[1])) +
                      gcd(abs(q[0] - r[0]), abs(q[1] - r[1])) +
                      gcd(abs(r[0] - p[0]), abs(r[1] - p[1]));

        // Calculate the number of interior points using Pick's Theorem
        long long ans = A - B / 2 + 1;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends