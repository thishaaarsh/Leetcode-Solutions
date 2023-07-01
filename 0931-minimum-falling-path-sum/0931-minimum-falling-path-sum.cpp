class Solution {
public:
    int solve(int i,int j, vector<vector<int>>& arr,vector<vector<int>>&dp){
        if(j<0 || j>=arr.size()) return 1e9;
        if(i==0) return arr[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int a = arr[i][j]+solve(i-1,j,arr,dp);
        int b = arr[i][j]+solve(i-1,j-1,arr,dp);
        int c = arr[i][j]+solve(i-1,j+1,arr,dp);
        return dp[i][j] = min(a,min(b,c));
    }
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int ans = INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0; i<n; i++){
            dp[n-1][i] = arr[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int a = 1e9,b=1e9,c=1e9;
                a = arr[i][j]+dp[i+1][j];
                if(j>0){
                    b = arr[i][j]+dp[i+1][j-1];
                }
                if(j+1<n){
                    c = arr[i][j]+dp[i+1][j+1];
                }
                dp[i][j] = min(a,min(b,c));
            }
        }
        for(int i=0; i<n; i++){
            ans = min(ans,dp[0][i]);
        }
        return ans;
    }
};