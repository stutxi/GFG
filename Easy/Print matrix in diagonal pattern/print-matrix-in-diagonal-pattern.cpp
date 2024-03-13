//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
        vector<int> ans;
        int n = mat.size();
        int row = 0, col = 0;
        bool isUp = true;
        int k = 0;

        while (k < n * n) {
            if (isUp) {
                while (row >= 0 && col < n) {
                    ans.push_back(mat[row][col]);
                    k++;
                    col++;
                    row--;
                }
                if (row < 0 && col <= n - 1)
                    row = 0;
                if (col == n)
                    row = row + 2, col--;
            } else {
                while (col >= 0 && row < n) {
                    ans.push_back(mat[row][col]);
                    k++;
                    row++;
                    col--;
                }

                if (col < 0 && row <= n - 1)
                    col = 0;
                if (row == n)
                    col = col + 2, row--;
            }

            isUp = !isUp;
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends