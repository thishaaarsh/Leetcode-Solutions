class Solution {
public:
    bool solve(vector<int>& arr,int n, int k,vector<vector<int>>&dp){
        if(k == 0) return true;
        if(n<0) return false;
        if(dp[n][k] != -1) return dp[n][k];
        bool take = false;
        if(arr[n] <= k){
            take = solve(arr,n-1,k-arr[n],dp);
        }
        bool nottake = solve(arr,n-1,k,dp);
        return dp[n][k] =  take || nottake;
    }
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0; 
        for(auto x : arr){
            sum+=x;
        }
        if(sum%2) return false;
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return solve(arr,n-1,sum/2,dp);
    }
};