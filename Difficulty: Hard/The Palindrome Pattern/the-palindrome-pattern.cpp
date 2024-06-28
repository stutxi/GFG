//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        
        //check each row for a palindrome
        for (int i = 0; i < n; i++) {
            if (isPalindrome(arr[i])) {
                return to_string(i) + " R";
            }
        }

        //check each column for a palindrome
        for (int j = 0; j < n; j++) {
            vector<int> column(n);
            for (int i = 0; i < n; i++) {
                column[i] = arr[i][j];
            }
            if (isPalindrome(column)) {
                return to_string(j) + " C";
            }
        }
        return "-1";
    }

private:
    bool isPalindrome(const vector<int>& sequence) {
        int left = 0, right = sequence.size() - 1;
        while (left < right) {
            if (sequence[left] != sequence[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends