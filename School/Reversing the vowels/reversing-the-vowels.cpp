//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public: 
        bool isVowel (char ch) {
            ch = tolower(ch);
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        }
        string modify (string s)
        {
            //code here.
            int l = 0, h = s.size() - 1;
            while (l < h) {
            if (isVowel(s[l]) && isVowel(s[h])) {
                swap(s[l], s[h]);
                l++, h--;
            } else if (isVowel(s[l]) == 0) {
                l++;
            } else {
                h--;
            }
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.modify (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends