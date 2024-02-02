//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int num = 0, i = 0, sign = 1; // +ve

        // Skip leading whitespace
        while (str[i] == ' ') {
            ++i;
        }

        // Handle sign
        if (i < str.size() && (str[i] == '-' || str[i] == '+')) {
            sign = str[i] == '+' ? 1 : -1;
            ++i;
        }

        // Process digits
        while (i < str.size() && isdigit(str[i])) {
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] > '7')) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num * 10 + (str[i] - '0');
            ++i;
        }
        while (i < str.size() && str[i] == ' ') {
            ++i;
        }
        if (i < str.size()) {
            return -1; 
        }
        return num * sign;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends