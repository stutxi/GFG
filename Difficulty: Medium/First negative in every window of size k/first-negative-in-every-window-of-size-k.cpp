//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> ans;
    deque<int> dq;
    
    // process first k elements
    for (int i = 0 ; i < K; i++) {
        int element = A[i];
        if (element < 0) {
            dq.push_back(i);
        }
    }
    
    // process remaining windows
    // removal and addition
    // remove old windows answer if not needed
  
    for (int i = K; i < N; i++) {
        if (!dq.empty()) {
            ans.push_back(A[dq.front()]);
        } else {
            ans.push_back(0);
        }
        
        // removal
        while (!dq.empty() && dq.front() <= i - K) {
            dq.pop_front();
        }
        
        // addition
        if (A[i] < 0) {
            dq.push_back(i);
        }
    }
    if (!dq.empty()) {
        ans.push_back(A[dq.front()]);
    } else {
        ans.push_back(0);
    }
    return ans;
 }