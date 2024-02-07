//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int maxRowIndex = -1; 
        int maxOnesCount = 0; 
        
        int row = 0; //top row
        int col = m - 1; //rightmost column
        
        while (row < n && col >= 0) {
            if (arr[row][col] == 1) {
                col--; //move left
                maxRowIndex = row; 
                maxOnesCount = m - col - 1; 
            } else {
                row++; //move down
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
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends