//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>> ans;
        sort(A.begin(), A.end());
        vector<int> combination;
        findCombination(A, B, combination, ans, 0);
        return ans;
    }


    void findCombination(vector<int>& arr, int target, vector<int>& combination, vector<vector<int>>& ans, int index) {
        if (target == 0) {
            ans.push_back(combination);
            return;
        }
        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1]) continue; 
            if (target - arr[i] >= 0) {
                combination.push_back(arr[i]);
                findCombination(arr, target - arr[i], combination, ans, i);
                combination.pop_back();
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends