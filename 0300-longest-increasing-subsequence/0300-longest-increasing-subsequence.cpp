class Solution {
public:
    int solve(int idx, int prev, int n, vector<int>&arr,vector<vector<int>>&dp){
        if(idx==n) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int nottake = solve(idx+1,prev,n,arr,dp);
        int take = -1e9;
        if(prev==-1 || arr[idx]>arr[prev]){
            take = 1+solve(idx+1,idx,n,arr,dp);
        }
        return dp[idx][prev+1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //return solve(0,-1,n,arr,dp);
        for(int i=n-1; i>=0; i--){
            for(int j=i-1; j>=-1; j--){
                int nottake = dp[i+1][j+1];
                int take = INT_MIN;
                if(j==-1 || arr[j] < arr[i]){
                    take = 1+dp[i+1][i+1];
                }
                dp[i][j+1] = max(take,nottake);
            }
        }
        return dp[0][0];
    }
};