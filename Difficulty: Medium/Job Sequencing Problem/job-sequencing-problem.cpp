//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool compare(Job a, Job b) 
{
    return a.profit > b.profit;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        // 1. sort jobs by profit in descending order
        sort(arr, arr + n, compare);
        
        // 2. find the maximum deadline to size the time slots array
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        // 3. initialize time slots array
        vector<bool> slot(maxDeadline + 1, false); // false -> empty
        
        int jobCount = 0;
        int maxProfit = 0;
        
        // 4. Iterate over all jobs
        for (int i = 0; i < n; ++i) {
            // try to place this job in a slot from its deadline to the start
            for (int j = arr[i].dead; j > 0; --j) {
                if (!slot[j]) { // if slot is available
                    slot[j] = true; // mark this slot as occupied
                    jobCount++; // increase job count
                    maxProfit += arr[i].profit; // add profit
                    break; // move to the next job
                }
            }
        }
        // return the result as a vector {number of jobs, maximum profit}
        return {jobCount, maxProfit};
    }
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends