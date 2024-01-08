//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends

int expand(char S[], int N, int i, int j) {
    int count = 0;
    while (i >= 0 && j < N && S[i] == S[j]) {
        if (j - i + 1 >= 2) { 
            count++;
        }
        i--;
        j++;
    }
    return count;
}

int CountPS(char S[], int N) {
    int totalCount = 0;

    for (int center = 0; center < N; center++) {
        int oddAns = expand(S, N, center, center);
        
        int evenAns = expand(S, N, center, center + 1);

        totalCount += oddAns + evenAns;
    }

    return totalCount;
}

