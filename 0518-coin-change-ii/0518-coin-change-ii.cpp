class Solution {
public:
    int solve(int n, int k, vector<int>&arr,vector<vector<int>>&dp){
        if(k==0) return 1;
        if(k<0 || n<0) return 0;
        if(dp[n][k] != -1) return dp[n][k];
        int nottake = solve(n-1,k,arr,dp);
        int take = 0;
        if(arr[n] <= k){
            take = solve(n,k-arr[n],arr,dp);
        }
        return dp[n][k] = take+nottake;
    }
    int change(int k, vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(n-1,k,arr,dp);
    }
};