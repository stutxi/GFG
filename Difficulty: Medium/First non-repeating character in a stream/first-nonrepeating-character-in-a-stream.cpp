//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char, int> freq;
		    queue<char> q;
		    string ans = "";
		    
		    for (char ch : A) {
		        freq[ch]++;
		        q.push(ch);
		    
    		    while (!q.empty() && freq[q.front()] > 1) {
    		            q.pop();
    		    } 
    		        
    		    if (!q.empty()) {
    		        ans += q.front();
    		    } else {
    		        ans += '#';
    		    }
		    }
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends