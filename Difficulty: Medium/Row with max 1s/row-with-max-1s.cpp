//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > arr) {
        // code here
        int n = arr.size(); // rows
        int m = arr[0].size(); // columns
        
        int maxRowIndex = -1;
        int maxOnesCount = 0;
        
        int row = 0; // top row
        int col = m - 1; // right most column
        
        while (row < n && col >= 0) {
            if (arr[row][col] == 1) {
                int count  = m - col;
                if (count > maxOnesCount) {
                    maxOnesCount = count;
                    maxRowIndex = row;
                }
                col--; // move left
            } else {
                row++; // move down
            }
        }
        return maxRowIndex;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends