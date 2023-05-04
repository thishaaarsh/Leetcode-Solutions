class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&arr,vector<vector<int>>&dp){
        if(j<0 || j>=arr.size()) return 1e9;
        if(i==0){
            return arr[0][j];
        }
        if(dp[i][j] != -1)return dp[i][j];
        int a = arr[i][j]+solve(i-1,j,arr,dp);
        int b = arr[i][j] + solve(i-1,j+1,arr,dp);
        int c = arr[i][j] + solve(i-1,j-1,arr,dp);
        return dp[i][j] = min(a,min(b,c));
        
    }
    int minFallingPathSum(vector<vector<int>>& arr){
       // int ans = INT_MAX;
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0; i<n; i++){
            dp[0][i] = arr[0][i];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int a = arr[i][j] + dp[i-1][j];
                int b = INT_MAX;
                if(j-1>=0){
                    b = arr[i][j]+dp[i-1][j-1];
                }
                int c = INT_MAX;
                if(j+1<n){
                    c = arr[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = min(a,min(b,c));
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};