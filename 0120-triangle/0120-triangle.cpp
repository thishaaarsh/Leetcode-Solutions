class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>& arr,vector<vector<int>>&dp){
        if(i==n-1) return arr[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int a = arr[i][j]+solve(i+1,j,n,arr,dp);
        int b = arr[i][j]+solve(i+1,j+1,n,arr,dp);
        return dp[i][j] = min(a,b);
    }
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,n,arr,dp);
    }
};