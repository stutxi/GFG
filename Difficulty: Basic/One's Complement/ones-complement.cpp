//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
class Solution{
public:
    int onesComplement(int n){
        //code here
        if (n == 0) {
            return 1;
        }
        
        int mask = 0;
        int temp = n;
        
        while (temp > 0) {
            mask = (mask << 1) | 1; // left shift mask by 1 and set last bit to 1
            temp >>= 1; // right shift temp by 1 (/2)
        }
        return n ^ mask; // flip bits using xor
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
        cout<<ob.onesComplement(n)<<"\n";
    }
}
// } Driver Code Ends