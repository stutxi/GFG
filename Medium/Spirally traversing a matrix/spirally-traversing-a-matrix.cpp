//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int total_elements = r * c;

        int startingRow = 0;
        int endingCol = c - 1; 
        int endingRow = r - 1; 
        int startingCol = 0;

        int count = 0;

        while (count < total_elements) {
            //starting row
            for (int i = startingCol; i <= endingCol; i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            //ending column
            for (int i = startingRow; i <= endingRow; i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            //ending row
            if (startingRow <= endingRow) {
                for (int i = endingCol; i >= startingCol; i--) {
                    ans.push_back(matrix[endingRow][i]);
                    count++;
                }
                endingRow--;
            }

            //starting column
            if (startingCol <= endingCol) {
                for (int i = endingRow; i >= startingRow; i--) {
                    ans.push_back(matrix[i][startingCol]);
                    count++;
                }
                startingCol++;
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends