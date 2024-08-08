//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        int n = q.size();
        
        queue<int> second;
        
        // push first half of queue in second queue
        for (int i = 0; i < n / 2; i++) {
            int temp = q.front();
            q.pop();
            second.push(temp);
        }
        
        // merge both halves - into the original queue
        // for (int i = 0; i < n / 2; i++) {
        //     int temp = second.front();
        //     second.pop();
            
        //     q.push(temp);
            
        //     temp = q.front();
        //     q.pop();
        //     q.push(temp);
        // }
        vector<int> ans;
        for (int i = 0; i < n / 2; i++) {
            int temp = second.front();
            second.pop();
            
            ans.push_back(temp);
            
            temp = q.front();
            q.pop();
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends