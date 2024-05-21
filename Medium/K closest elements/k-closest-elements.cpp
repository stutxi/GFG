//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                left = mid;
                break;
            } else if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        vector<int> ans(k);
        int count = 0, leftCount = 0, rightCount = 0;
        if (left >= 0 && left < n && arr[left] == x) {
            leftCount = left - 1;
            rightCount = left + 1;
        } else {
            leftCount = left - 1;
            rightCount = left;
        }
        while (leftCount >= 0 && rightCount < n && count < k) {
            if (x - arr[leftCount] < arr[rightCount] - x)
               ans[count++] = arr[leftCount--];
            else
               ans[count++] = arr[rightCount++];
        }
        if (leftCount < 0) {
            for (int i = rightCount; count < k; i++)
                ans[count++] = arr[i];
        } else if (rightCount >= n) {
            for (int i = leftCount; count < k; i--)
                ans[count++] = arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends