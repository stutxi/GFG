//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int minimumInteger(int N, vector<int> &A) {
        // code here
        long long sum = 0;
        long long ans = -1;
        sort(A.begin(), A.end());
        for (auto num : A) {
            sum += num;
        }
        int start = 0; 
        int end = N - 1;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            if (sum <= (long long)N * A[mid]) {
                ans = A[mid];
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.minimumInteger(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends