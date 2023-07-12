class Solution {
public:
    int solve(int i, int j, vector<int>&arr,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k=i; k<=j; k++){
            int cost = arr[j+1]-arr[i-1]+
                solve(i,k-1,arr,dp)+solve(k+1,j,arr,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        return solve(1,cuts.size()-2,cuts,dp);
    }
};