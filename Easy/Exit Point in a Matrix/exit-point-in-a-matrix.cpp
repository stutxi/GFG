//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        vector<int> ans(2, 0);
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int row = 0, col = 0, directionIndex = 0;
        while (true) {
            if (row < 0 || row >= n || col < 0 || col >= m) {
                ans[0] = row - directions[directionIndex].first;
                ans[1] = col - directions[directionIndex].second;
                break;
            }
            if (matrix[row][col] == 0) {
                row += directions[directionIndex].first;
                col += directions[directionIndex].second;
            } else {
                directionIndex = (directionIndex + 1) % 4;
                matrix[row][col] = 0;
                row += directions[directionIndex].first;
                col += directions[directionIndex].second;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends