//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        if (n == 0) {
            return -1;
        }
        
        int ans = 0;
        
        for (int i = 1; i < n; i++) {
            if (mat[ans][i] == 1) {
                ans = i;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (i != ans) {
                if (mat[ans][i] == 1 || mat[i][ans] == 0) {
                    return -1;
                }
            }
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
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends