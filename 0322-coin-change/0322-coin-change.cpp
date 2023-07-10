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
    int coinChange(vector<int>& arr, int k){
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(k+1,0));
       //int ans = solve(n-1,coins,amount,dp);
        for(int i=0; i<n; i++){
            for(int j=0; j<=k; j++){
                if(j==0){
                    dp[i][j] = 0;
                }
                else if(i==0){
                    if(j%arr[i] == 0){
                        dp[i][j] = j/arr[i];
                    }
                    else{
                        dp[i][j] = 1e9;
                    }
                }
                else{
                    int nottake = dp[i-1][j];
                    int take = 1e9;
                    if(arr[i] <= j){
                        take = 1+dp[i][j-arr[i]];
                    }
                    dp[i][j] = min(take,nottake);
                }
                
            }
        }
        if(dp[n-1][k] >= 1e9) return -1;
        return dp[n-1][k];
    }
    
};