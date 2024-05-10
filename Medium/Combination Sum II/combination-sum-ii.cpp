//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(), arr.end());
        vector<std::vector<int>> ans;
        vector<int> path;
        backtrack(arr, k, 0, path, ans);
        return ans;
    }
    
    void backtrack(vector<int>& arr, int target, int start, vector<int>& path, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < arr.size(); ++i) {
            if (i > start && arr[i] == arr[i - 1]) {
                continue;
            }
            if (target - arr[i] < 0) {
                break;
            }
            path.push_back(arr[i]);
            backtrack(arr, target - arr[i], i + 1, path, ans);
            path.pop_back();
        }
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
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends