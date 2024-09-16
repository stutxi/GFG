//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // code here
        stack<int> st;
        st.push(-1); 
        int ans = 0;
    
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                st.push(i); 
            } else {
                st.pop(); 
                if (st.empty()) {
                    st.push(i); 
                } else {
                    ans = max(ans, i - st.top());
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
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends