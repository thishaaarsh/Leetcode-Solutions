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
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,n,arr,dp);
    }
};