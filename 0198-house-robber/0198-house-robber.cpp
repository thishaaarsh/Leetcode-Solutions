class Solution {
public:
    int solve(int i, vector<int>&arr,vector<int>&dp){
        if(i<0)return 0;
        if(dp[i] != -1) return dp[i];
        int a = arr[i]+solve(i-2,arr,dp);
        int b = solve(i-1,arr,dp);
        return dp[i] = max(a,b);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
    }
};