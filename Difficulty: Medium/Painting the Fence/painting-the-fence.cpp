//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
//     const int mod = 1000000007;
//     long long countWays(int n, int k){
//         // code here
//         if (n == 1) {
//             return k % mod;
//         }
//         if (n == 2) {
//             return (k + k * (k - 1)) % mod;
//         }
        
//         long long prev2 = k % mod;
//         long long prev1 = (k + k * (k - 1)) % mod;
//         long long curr;
//         for (int i = 3; i <= n; i++) {
//             curr = ((prev1 + prev2) * (k - 1)) % mod;
//             prev2 = prev1;
//             prev1 = curr;
//         }
//         return curr;
//     }
// };

// ye bhi nahi chala ab to dimaag kharab ho raha hai

// class Solution{
//     public:
//     const int mod = 1000000007;
//     long long countWays(int n, int k){
//         // code here
//         if (n == 1) {
//             return k % mod;
//         }
//         if (n == 2) {
//             return (k + k * (k - 1)) % mod;
//         }
//         vector<long long> dp(n + 1, -1);
//         dp[1] = k % mod;
//         dp[2] = k + k * (k - 1) % mod;
        
//         for (int i = 3; i <= n; i++) {
//             dp[i] = (dp[i - 1] + dp[i - 2]) % mod * (k - 1) % mod; 
//         }
//         return dp[n];
//     }
// };









// didnt work, will see later

// class Solution{
//     public:
    const int mod = 1000000007;
    long long countWays(long long n, long long k){
        // code here
        vector<long long> dp(n + 1, -1);
        return memo(n, k, dp);
    }
    
    long long memo(long long n, long long k, vector<long long>& dp) {
        // base case 
        if (n == 1) {
            return k % mod;
        }
        
        if (n == 2) {
            return (k + k * (k - 1)) % mod;
        }
        
        if (dp[n] != -1) {
            return dp[n];
        }
        
        dp[n] = (memo(n - 1, k, dp) + memo(n - 2, k, dp)) % mod * (k - 1) % mod;
        return dp[n];
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends