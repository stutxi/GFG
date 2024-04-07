//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        int n = S.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int lowerCount = 0;
            int upperCount = 0;

            for (int j = i; j < n; ++j) {
                if (islower(S[j])) {
                    lowerCount++;
                } else {
                    upperCount++;
                }
                if (lowerCount == upperCount) {
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends