//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int sumOfDigits(int N) {
        int sum = 0;
        while (N > 0) {
            int digit = N % 10;
            sum += digit;
            N /= 10;
        }
        return sum;
    }
    int isDivisible(int N) {
        // code here
        if (N % sumOfDigits(N) == 0) {
            return 1;
        } else {
            return 0;
        }
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
        cout << ob.isDivisible(N) << "\n";
    }
}
// } Driver Code Ends