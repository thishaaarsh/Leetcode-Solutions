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
        vector<vector<int>>dp(n,vector<int>(k+1,0));
        //return solve(n-1,k,arr,dp);
        for(int i=0; i<n; i++){
            for(int j=0; j<=k; j++){
                if(j==0){
                    dp[i][j] = 1;
                }
                if(i==0){
                    if(j%arr[i] == 0){
                        dp[i][j] = 1;
                    }
                    continue;
                }
                int nottake = dp[i-1][j];
                int take = 0;
                if(arr[i] <= j){
                    take = dp[i][j-arr[i]];
                }
                dp[i][j] = take+nottake;
            }
        }
        return dp[n-1][k];
    }
};