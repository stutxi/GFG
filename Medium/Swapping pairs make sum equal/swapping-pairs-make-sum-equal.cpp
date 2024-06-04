//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        int sumA = 0, sumB = 0;
        
        for (int i = 0; i < n; i++) {
            sumA += a[i];
        }
        for (int i = 0; i < m; i++) {
            sumB += b[i];
        }
        
        // check if the difference is even
        int diff = sumA - sumB;
        if (diff % 2 != 0) {
            return -1;
        }
        
        int target = diff / 2;
        
        sort(b, b + m);
        
        for (int i = 0; i < n; i++) {
            int needed = a[i] - target;
            if (binarySearch(b, 0, m - 1, needed)) {
                return 1;
            }
        }
        return -1;
    }

private:
    bool binarySearch(int b[], int start, int end, int value) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (b[mid] == value) {
                return true;
            } else if (b[mid] < value) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends