//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        vector<int> freq(26, 0);
        
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int x = 0;
        int y = 0;
        
        for (int i = 0; i < 26; i++) {
            int count = freq[i];
            if (count > 0) {
                if ((i + 1) % 2 == 0) { 
                    if (count % 2 == 0) {  
                        x++;
                    }
                } else { 
                    if (count % 2 != 0) {
                        y++;
                    }
                }
            }
        }
        if ((x + y) % 2 == 0) {
            return "EVEN";
        } else {
            return "ODD";
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends