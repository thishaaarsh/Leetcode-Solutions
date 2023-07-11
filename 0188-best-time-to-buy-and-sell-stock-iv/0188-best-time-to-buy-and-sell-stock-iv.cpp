class Solution {
public:
    int solve(int i, int j, int n ,int k, 
              vector<int>&arr,vector<vector<int>>&dp){
        if(i==n || j==k) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int profit = 0;
        if(j%2==0){
            profit = max(-arr[i]+solve(i+1,j+1,n,k,arr,dp),solve(i+1,j,n,k,arr,dp));
        }
        else{
            profit = max(arr[i]+solve(i+1,j+1,n,k,arr,dp),solve(i+1,j,n,k,arr,dp));
        }
        return dp[i][j] = profit;
    }
    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,-1));
        //return solve(0,0,n,2*k,arr,dp);
        for(int i=n; i>=0; i--){
            for(int j=2*k; j>=0; j--){
                if(i==n || j==2*k){
                    dp[i][j] = 0;
                }
                else{
                    int profit;
                    if(j%2==0){
                        profit = max(-arr[i]+dp[i+1][j+1],dp[i+1][j]);
                    }
                    else
                        profit = max(arr[i]+dp[i+1][j+1],dp[i+1][j]);
                    dp[i][j] = profit;
                }
            }
        }
        return dp[0][0];
    }
};