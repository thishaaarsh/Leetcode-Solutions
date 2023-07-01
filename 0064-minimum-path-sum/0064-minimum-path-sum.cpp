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
        vector<vector<int>>dp(n,vector<int>(m,0));
        //return solve(n-1,m-1,arr,dp);
        dp[0][0] = arr[0][0];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 and j==0) continue;
                int a = 1e9,b=1e9;
                if(i>0){
                    a = arr[i][j]+dp[i-1][j];
                }
                if(j>0)
                    b = arr[i][j]+dp[i][j-1];
                dp[i][j] = min(a,b);
            }
        }
        return dp[n-1][m-1];
    }
};