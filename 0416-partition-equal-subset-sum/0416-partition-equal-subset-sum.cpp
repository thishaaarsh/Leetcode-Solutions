class Solution {
public:
    bool solve(int i, int target,vector<int>& arr,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i==0) return target == arr[0];
        if(dp[i][target] != -1) return dp[i][target];
        bool nottake = solve(i-1,target,arr,dp);
        bool take =  false;
        if(arr[i] <= target){
            take = solve(i-1,target-arr[i],arr,dp);
        }
        return dp[i][target] =  take || nottake;
    }
    bool canPartition(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        if(sum%2) return false;
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return solve(n-1,sum/2,arr,dp);
    }
};