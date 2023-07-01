class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& arr,vector<vector<int>>&dp ){
        if(i==0 and j==0) return arr[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] =  min(solve(i-1,j,arr,dp),solve(i,j-1,arr,dp))+arr[i][j];
    }
    int minPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,arr,dp);
    }
};