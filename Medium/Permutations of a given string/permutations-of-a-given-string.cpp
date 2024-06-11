//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void permutation(string& S, int F, set<string>& ans) {
	        if (F == S.length()) {
	            ans.insert(S);
	            return;
	        }
	        for (int i = F; i < S.length(); i++) {
	            swap(S[i], S[F]);
	            permutation(S, F + 1, ans);
	            swap(S[i], S[F]);
	        }
	    }
	    
		vector<string>find_permutation(string S) {
		    set<string> ans;
		    permutation(S, 0, ans);
		    return vector<string> (ans.begin(), ans.end());
		}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends