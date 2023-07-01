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
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0; i<n; i++){
            dp[n-1][i] = arr[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                int up = arr[i][j]+dp[i+1][j];
                int dia = arr[i][j]+dp[i+1][j+1];
                dp[i][j] = min(up,dia);
            }
        }
        return dp[0][0];
        //return solve(0,0,n,arr,dp);
    }
};