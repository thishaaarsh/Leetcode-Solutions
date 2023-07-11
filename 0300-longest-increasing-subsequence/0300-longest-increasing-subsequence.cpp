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
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,n,arr,dp);
    }
};