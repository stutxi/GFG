//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends

class Info {
public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int a, int b, int c) : data(a), rowIndex(b), colIndex(c) {}
};

class compare {
public:
    bool operator()(Info* a, Info* b) {
        return a->data > b->data;
    }
};

// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
        priority_queue<Info*, vector<Info*>, compare> pq;
        int maxElement = INT_MIN;
        int minElement = INT_MAX;

        for (int i = 0; i < k; i++) {
            int element = KSortedArray[i][0];
            pq.push(new Info(element, i, 0));
            maxElement = max(maxElement, element);
            minElement = min(minElement, element);
        }

        int ansStart = minElement;
        int ansEnd = maxElement;

        while (!pq.empty()) {
            Info* topNode = pq.top();
            pq.pop();
            minElement = topNode->data; // update current minimum

            // check if the current range is smaller than the previous one
            if ((maxElement - minElement) < (ansEnd - ansStart)) {
                ansStart = minElement;
                ansEnd = maxElement;
            }

            // move to the next element in the row (if available)
            if (topNode->colIndex + 1 < n) {
                int newElement = KSortedArray[topNode->rowIndex][topNode->colIndex + 1];
                maxElement = max(maxElement, newElement);
                pq.push(new Info(newElement, topNode->rowIndex, topNode->colIndex + 1));
            } else {
                delete topNode;
                break;
            }
            delete topNode;
        }

        while (!pq.empty()) {
            Info* node = pq.top();
            pq.pop();
            delete node;
        }

        return {ansStart, ansEnd};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends