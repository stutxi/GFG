//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int n = S.size();
        //reverse entire string
        reverse(S.begin(), S.end());
        //reverse each word individually
        int left = 0;
        for (int right = 0; right <= n; right++) {
            if (right == n || S[right] == '.') {
                reverse(S.begin() + left, S.begin() + right);
                left = right + 1;
            }
        }
        return S;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends