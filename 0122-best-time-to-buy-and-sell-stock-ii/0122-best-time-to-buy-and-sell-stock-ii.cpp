class Solution {
public:
    int solve(int i, int buy, int n, vector<int>&arr,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit;
        if(buy){
            profit = max(-arr[i]+solve(i+1,0,n,arr,dp),solve(i+1,1,n,arr,dp));
        }
        else
            profit = max(arr[i]+solve(i+1,1,n,arr,dp),solve(i+1,0,n,arr,dp));
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,n,arr,dp);
    }
};