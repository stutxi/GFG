//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
    int isTriangular(int N){
        //code here
        long long start = 0, end = N;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long triangular = mid * (mid + 1) / 2;
            
            if (triangular == N) {
                return 1;
            } else if (triangular < N) {
                start = mid + 1; 
            } else {
                end = mid - 1; 
            }
        }
        return 0; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        cout<<ob.isTriangular(N)<<"\n";
    }
}
// } Driver Code Ends