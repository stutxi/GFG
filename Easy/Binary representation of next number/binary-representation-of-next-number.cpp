//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int zeroCount = 0;
        for (auto ch : s) {
            if (ch == '0') {
                zeroCount++;
            } else {
                break;
            }
        }
        
        int start = 0;
        int end = s.size() - 1;
        int carry = 0;

        string addOne = "1";
        string ans = "";
        
        while (start >= 0 || end >= zeroCount || carry > 0) {
            int sum = carry;
            if (start >= 0) {
                sum += addOne[start] - '0';
                start--;
            }
            if (end >= 0) {
                sum += s[end] - '0';
                end--;
            }
            ans.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends