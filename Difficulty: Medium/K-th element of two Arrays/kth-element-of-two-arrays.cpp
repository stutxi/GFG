//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int n = arr1.size();
        int m = arr2.size();

        // ensure arr1 is the smaller array
        if (n > m) {
            return kthElement(k, arr2, arr1);
        }

        int low = max(0, k - m);
        int high = min(k, n);

        while (low <= high) {
            int i1 = (low + high) / 2;
            int i2 = k - i1;

            int min1 = (i1 == n) ? INT_MAX : arr1[i1];
            int max1 = (i1 == 0) ? INT_MIN : arr1[i1 - 1];
            int min2 = (i2 == m) ? INT_MAX : arr2[i2];
            int max2 = (i2 == 0) ? INT_MIN : arr2[i2 - 1];

            if (max1 <= min2 && max2 <= min1) {
                return max(max1, max2);
            } else if (max1 > min2) {
                high = i1 - 1;
            } else {
                low = i1 + 1;
            }
        }
        return -1; 
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends