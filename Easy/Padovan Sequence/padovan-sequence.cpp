//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
        const int mod = 1000000007;
        int padovan[3] = {1, 1, 1};

        if (n < 3)
            return padovan[n];

        for (int i = 3; i <= n; i++)
        {
            int nextPadovan = (padovan[1] + padovan[0]) % mod;
            padovan[0] = padovan[1];
            padovan[1] = padovan[2];
            padovan[2] = nextPadovan;
        }
        return padovan[2];
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends