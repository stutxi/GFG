//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector <int> nFibonacci(int N){
        //code here
        vector<int> ans;
        int prev2 = 0;
        int prev1 = 1;
        ans.push_back(0);

        while(prev1 <= N) {
            ans.push_back(prev1);
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        Solution ob;
        vector <int> ans=ob.nFibonacci(N);
        for(int u:ans)
         cout<<u<<" ";
        cout<<"\n"; 
    }
}
// } Driver Code Ends