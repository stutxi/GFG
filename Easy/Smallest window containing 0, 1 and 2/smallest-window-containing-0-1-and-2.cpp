//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
    int n = S.length();
    int count[3] = {0};  
    int uniqueCount = 0; 
    int minLength = INT_MAX;
    int left = 0, right = 0;
    while (right < n) {
        count[S[right] - '0']++;  
        if (count[S[right] - '0'] == 1) {
            uniqueCount++;  
        }
        while (uniqueCount == 3) {
            minLength = min(minLength, right - left + 1); 

            count[S[left] - '0']--;

            if (count[S[left] - '0'] == 0) {
                uniqueCount--; 
            }
            left++; 
        }
        right++; 
    }

    return (minLength == INT_MAX) ? -1 : minLength;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends