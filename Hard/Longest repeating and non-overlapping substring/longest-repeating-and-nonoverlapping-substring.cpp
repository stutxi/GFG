//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        string ans;
        for(int i = 0, j = 0; j < n; j++) {
            string str = s.substr(i, j - i + 1);
            if(s.find(str, j + 1) !=  -1) {
                ans = str;
            }
            else {
               i++; 
            }
        }
        return ans == "" ? "-1" : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends