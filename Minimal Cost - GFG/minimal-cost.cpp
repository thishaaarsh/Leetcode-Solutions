//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int i, vector<int>&arr,int k,vector<int>&dp){
        if(i==0) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i-j>=0){
                int curr = solve(i-j,arr,k,dp)+abs(arr[i]-arr[i-j]);
                ans = min(ans,curr);
            }
        }
        return dp[i] = ans;
    }
    int minimizeCost(vector<int>& arr, int n, int k) {
        // Code here
        vector<int>dp(n,-1);
        return solve(n-1,arr,k,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends