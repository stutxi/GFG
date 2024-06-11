//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    bool isFour(int n) {
        while (n > 0) {
            if (n % 10 == 4) {
                return true;
            }
            n /= 10;
        }
        return false;
    }
  public:
    int countNumberswith4(int n) {
        // code here
        int count = 0;
        for (int i = 0; i <= n; i++) {
            if (isFour(i)) {
                count++;
            }
        }
        return count;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends