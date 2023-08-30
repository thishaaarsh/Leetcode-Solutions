class Solution {
public:
    int solve(int i, int n, vector<int>&arr,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        int a = arr[i]+solve(i+2,n,arr,dp);
        int b = solve(i+1,n,arr,dp);
        return dp[i] = max(a,b);
    }
    int rob(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return arr[0];
        vector<int>dp(n,-1);
        vector<int>dp1(n,-1);
        int a = solve(0,n-1,arr,dp);
        int b = solve(1,n,arr,dp1);
        return max(a,b);
    }
};