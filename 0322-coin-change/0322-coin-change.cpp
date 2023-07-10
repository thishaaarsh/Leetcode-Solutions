class Solution {
public:
    int solve(int i,vector<int>&arr,int k,vector<vector<int>>&dp){
        if(k==0) return 0;
        if(k<0 || i<0) return 1e9;
        if(dp[i][k] != -1) return dp[i][k];
        int take = 1+solve(i,arr,k-arr[i],dp);
        int nottake = solve(i-1,arr,k,dp);
        return dp[i][k] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       int ans = solve(n-1,coins,amount,dp);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};