//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        int lowerMask = (1 << 4) - 1;
        int upperMask = ~lowerMask;

        int lowerNibble = n & lowerMask;
        int upperNibble = n & upperMask;

        int swapped = (lowerNibble << 4) | (upperNibble >> 4);

        return swapped;
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
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends