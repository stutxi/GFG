//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
    // Base case: if the stack is empty, return
    if (s.empty()) {
        return;
    }

    // Remove the top element from the stack
    int topElement = s.top();
    s.pop();

    // Recursively sort the remaining stack
    sort();

    // Temporary stack to hold elements while inserting the topElement
    stack<int> tempStack;

    // Insert the topElement in sorted order
    while (!s.empty() && s.top() > topElement) {
        tempStack.push(s.top());
        s.pop();
    }

    s.push(topElement);

    // Push the elements from tempStack back to the original stack
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}