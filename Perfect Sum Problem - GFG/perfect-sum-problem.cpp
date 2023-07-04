//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	int solve(int arr[], int n, int sum,int i,vector<vector<int>>&dp){
	    if(i>n || sum<0) return 0;
	    if(i==n and sum == 0){
	        return 1;
	    }
	    if(dp[i][sum] != -1) return dp[i][sum];
	    int a = solve(arr,n,sum,i+1,dp);
	    int b = solve(arr,n,sum-arr[i],i+1,dp);
	    return dp[i][sum] = (a+b)%mod;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,n,sum,0,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends