class Solution {
public:
    int solve(vector<vector<int>>& arr, int m, int n,vector<vector<int>>& dp){
        if(m>=0 and n>=0 and arr[m][n] == 1){
            return 0;
        }
        if(m==0 and n==0) return 1;
        if(m<0 or n<0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int up = solve(arr,m-1,n,dp);
        int left = solve(arr,m,n-1,dp);
        return dp[m][n] =  up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(arr,m-1,n-1,dp);
    }
};