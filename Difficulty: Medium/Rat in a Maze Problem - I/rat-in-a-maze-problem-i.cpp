//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> paths;
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        if (mat[0][0] == 1 && mat[mat.size() - 1][mat[0].size() - 1] == 1) {
            findPathsUtil(mat, 0, 0, visited, "", paths);
        }
        if (paths.empty()) {
            paths.push_back("-1");
        }
        return paths;
    }

private:
    void findPathsUtil(vector<vector<int>>& mat, int x, int y, vector<vector<bool>>& visited, string path, vector<string>& paths) {
        int n = mat.size();
        int m = mat[0].size();

        if (x == n - 1 && y == m - 1) {
            paths.push_back(path);
            return;
        }

        visited[x][y] = true;

        //move down
        if (isSafe(mat, x + 1, y, visited)) {
            findPathsUtil(mat, x + 1, y, visited, path + "D", paths);
        }

        //move up
        if (isSafe(mat, x - 1, y, visited)) {
            findPathsUtil(mat, x - 1, y, visited, path + "U", paths);
        }

        //move right
        if (isSafe(mat, x, y + 1, visited)) {
            findPathsUtil(mat, x, y + 1, visited, path + "R", paths);
        }

        //move left
        if (isSafe(mat, x, y - 1, visited)) {
            findPathsUtil(mat, x, y - 1, visited, path + "L", paths);
        }

        visited[x][y] = false;
    }

    bool isSafe(vector<vector<int>>& mat, int x, int y, vector<vector<bool>>& visited) {
        int n = mat.size();
        int m = mat[0].size();
        return (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1 && !visited[x][y]);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends