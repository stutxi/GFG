//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int ans = 0;
        int n = arr.size();
        vector<int> leftSmaller(n, 0);
        vector<int> rightSmaller(n, 0);
        
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                leftSmaller[i] = st.top();
            } else {
                leftSmaller[i] = 0;
            }
            st.push(arr[i]);
        }
        
        while (!st.empty()){
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                rightSmaller[i] = st.top();
            } else {
                rightSmaller[i] = 0;
            }
            st.push(arr[i]);
        }
        
        for (int i = 0; i < n; i++) {
            int diff = abs(leftSmaller[i] - rightSmaller[i]);
            ans = max(ans, diff);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends