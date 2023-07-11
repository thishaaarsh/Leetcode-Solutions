class Solution {
public:
    int solve(int i, int buy, int n, vector<int>&arr,vector<vector<int>>&dp){
        if(i>=n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit;
        if(buy){
            profit = max(-arr[i]+solve(i+1,0,n,arr,dp),solve(i+1,1,n,arr,dp));
        }
        else
            profit = max(arr[i]+solve(i+2,1,n,arr,dp),solve(i+1,0,n,arr,dp));
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& arr) {
        int n  = arr.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        //return solve(0,1,n,arr,dp);
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                int profit;
                if(j){
                    profit = max(-arr[i]+dp[i+1][0],dp[i+1][1]);
                }
                else
                    profit = max(arr[i]+dp[i+2][1],dp[i+1][0]);
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};