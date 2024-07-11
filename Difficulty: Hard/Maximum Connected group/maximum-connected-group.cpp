//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dfs(vector<vector<int>>& grid, int i, int j, int index) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
            return 0;
        }

        grid[i][j] = index;

        int count = dfs(grid, i + 1, j, index) + dfs(grid, i - 1, j, index) +
                    dfs(grid, i, j + 1, index) + dfs(grid, i, j - 1, index);
        return count + 1;
    }

    void neighbours(vector<vector<int>>& grid, int i, int j, set<int>& s) {
        int n = grid.size();
        if (i > 0) {
            s.insert(grid[i - 1][j]);
        }
        if (j > 0) {
            s.insert(grid[i][j - 1]);
        }
        if (i < n - 1) {
            s.insert(grid[i + 1][j]);
        }
        if (j < n - 1) {
            s.insert(grid[i][j + 1]);
        }
    }

    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0, index = 2;

        map<int, int> componentSize;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    componentSize[index] = dfs(grid, i, j, index);
                    ans = max(ans, componentSize[index++]);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    set<int> s;
                    neighbours(grid, i, j, s);
                    int count = 1;
                    for (int compIndex : s) {
                        if (compIndex > 1) {
                            count += componentSize[compIndex];
                        }
                    }
                    ans = max(ans, count);
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
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends