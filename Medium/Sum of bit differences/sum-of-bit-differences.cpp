//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
        long long ans = 0;
        for (long long i = 0; i < 32; i++) {
            long long zeroCount = 0;
            long long oneCount = 0;
            for (long long j = 0; j < n; j++) {
                long long bit = (arr[j] & (1 << i));
                if (bit == 0)
                    zeroCount++;
                else
                    oneCount++;
            }
            ans += zeroCount * oneCount;
        }
        return ans * 2;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends