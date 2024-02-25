//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int, int> prefixSumIndex; 
        int maxLength = 0;
        int currSum = 0;

        for (int i = 0; i < n; i++) {
            currSum += A[i];
            if (currSum == 0) {
                maxLength = i + 1;
            }
            else if (prefixSumIndex.find(currSum) != prefixSumIndex.end()) {
                maxLength = max(maxLength, i - prefixSumIndex[currSum]);
            }
            else {
                prefixSumIndex[currSum] = i;
            }
        }
        return maxLength;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends