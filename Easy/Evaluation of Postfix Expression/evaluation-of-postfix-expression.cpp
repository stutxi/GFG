//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> stack;
        
        for (ch : S) {
            if (isdigit(ch)) {
                stack.push(ch - '0');
            } else {
                int val2 = stack.top();
                stack.pop();
                int val1 = stack.top();
                stack.pop();
                
                switch(ch) {
                    case '*':
                    stack.push(val1 * val2);
                    break;
                    
                    case '/':
                    stack.push(val1 / val2);
                    break;
                    
                    case '+':
                    stack.push(val1 + val2);
                    break;
                    
                    case '-':
                    stack.push(val1 - val2);  
                    break;
                }
            }
        }
        return stack.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends