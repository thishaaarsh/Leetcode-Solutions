class Solution {
public:
    int solve(int i, int buy, int tra, int n , vector<int>&arr,
              vector<vector<vector<int>>>&dp){
        if(i==n || tra == 0 ) return 0;
        if(dp[i][buy][tra] != -1) return dp[i][buy][tra];
        int profit;
        if(buy){
            profit = max(-arr[i]+solve(i+1,0,tra,n,arr,dp),
                         solve(i+1,1,tra,n,arr,dp));
        }
        else{
            profit = max(arr[i]+solve(i+1,1,tra-1,n,arr,dp),
                         solve(i+1,0,tra,n,arr,dp));
        }
        return dp[i][buy][tra] = profit;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        //int dp[n][2][3] = {-1};
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
       // return solve(0,1,2,n,arr,dp);
        for(int i=n; i>=0; i--){
            for(int j=0; j<2;j++){
                for(int k=0; k<=2; k++){
                    if(k==0 || i==n){
                        dp[i][j][k] = 0;
                        
                    }
                    else{
                        int profit;
                        if(j==0){
                            profit = max(-arr[i]+dp[i+1][1][k],dp[i+1][0][k]);
                        }
                        else{
                            profit = max(arr[i]+dp[i+1][0][k-1],dp[i+1][1][k]);
                        }
                        dp[i][j][k] = profit;
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};