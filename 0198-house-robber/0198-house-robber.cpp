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
        vector<int>dp(n,0);
        if(n==1) return nums[0];
        if(n==0) return 0;
       // return solve(n-1,nums,dp);
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);
        for(int i=2; i<n; i++){
            int a = nums[i]+dp[i-2];
            int b = dp[i-1];
            dp[i] = max(a,b);
        }
        return dp[n-1];
    }
};