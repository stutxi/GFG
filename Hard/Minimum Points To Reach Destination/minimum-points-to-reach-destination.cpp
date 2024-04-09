//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // Your code goes here
        for (int row = m - 1; row >= 0; row--) {
            for (int col = n - 1; col >= 0; col--) {
                if (row == m - 1 && col == n - 1) {
                    points[row][col] = max(1, 1 - points[row][col]);
                } else if (row == m - 1) {
                    points[row][col] = max(1, points[row][col + 1] - points[row][col]);
                } else if (col == n - 1) {
                    points[row][col] = max(1, points[row + 1][col] - points[row][col]);
                } else {
                    int minPointsOnExit = min(points[row + 1][col], points[row][col + 1]);
                    points[row][col] = max(1, minPointsOnExit - points[row][col]);
                }
            }
        }
        return points[0][0];
    }
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends