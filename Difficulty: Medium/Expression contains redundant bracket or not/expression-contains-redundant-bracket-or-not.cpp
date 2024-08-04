//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
    stack<char> st;
    
    for (char ch : s) {
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } else if (ch == ')') {
            int operatorCount = 0;
            while (!st.empty() && st.top() != '(') {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
                    operatorCount++;
                }
                st.pop();
            }
            if (!st.empty()) {
                st.pop();   
            }
            if (operatorCount == 0) {
                return true;
            }
        }
    }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {

        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << res << endl;
    }
}

// } Driver Code Ends