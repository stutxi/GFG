//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        // Your code here
        int freqTable[256] = {0};
        for (int i = 0; i < a.size(); i++) {
            freqTable[a[i]]++;
        }
        for (int i = 0; i < b.size(); i++) {
            freqTable[b[i]]--;
        }
        for (int i = 0; i < 256; i++) {
            if (freqTable[i] != 0) {
                return false;
            }
        }
        return true;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends