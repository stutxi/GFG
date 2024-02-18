//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        const int mod = 1000000007;
        vector<long long> ans;
        ans.push_back(1);
        for (int i = 1; i < n; i++) {
            vector<long long> newRow(i + 1);
            newRow[0] = 1; 
            newRow[i] = 1; 
            
            for (int j = 1; j < i; j++) {
                newRow[j] = (ans[j - 1] + ans[j]) % mod;
            }
            ans = move(newRow);
        }
        return ans;
    }
};

//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends