//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Helper function to determine if a given max distance 'mid' is feasible with 'k' additional stations
    bool isPossible(vector<int>& stations, double mid, int k) {
        int count = 0;
        int n = stations.size();
        for (int i = 1; i < n; ++i) {
            int distance = stations[i] - stations[i - 1];
            count += (int)(distance / mid);
        }
        return count <= k;
    }

    double findSmallestMaxDist(vector<int>& stations, int k) {
        double start = 0.0;
        double end = stations.back() - stations.front();
        double ans = end;

        while (end - start > 1e-6) {
            double mid = start + (end - start) / 2.0;
            if (isPossible(stations, mid, k)) {
                ans = mid;
                end = mid;
            } else {
                start = mid;
            }
        }
        return round(ans * 100.0) / 100.0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends