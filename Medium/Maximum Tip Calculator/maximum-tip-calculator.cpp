//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<pair<long long, int>> diff;
        long long tipA = 0;
        long long tipB = 0;
        int maxA = x;
        int maxB = y;
        
        for(int i = 0 ; i < n; i++) {
            long long difference = abs(arr[i] - brr[i]);
            diff.push_back(make_pair(difference, i));
        }
        
        sort(diff.begin(), diff.end(), greater<pair<long long, int>>());
        
        for (auto a: diff) {
            if (maxA > 0 && maxB > 0) {
                if (arr[a.second] >= brr[a.second]) {
                    tipA += arr[a.second];
                    maxA--;
                } else {
                    tipB += brr[a.second];
                    maxB--;
                }
            } else if (maxB > 0) {
                tipB += brr[a.second];
                maxB--;
            } else if (maxA > 0) {
                tipA += arr[a.second];
                maxA--;
            } else {
                break;
            }
        }
        
        return tipA + tipB;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends