class Solution {
public:
    bool solve(int i, int j, int sum, int m,vector<int>&arr,vector<vector<int>>&dp){
        //if(i==j) return true;
        if(sum<m) return false;
        if(i>j) return false;
        if(i==j || i+1==j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(i+1,j,sum-arr[i],m,arr,dp)||solve(i,j-1,sum-arr[j],m,arr,dp);
    }
    bool canSplitArray(vector<int>& nums, int m) {
        int sum = 0;
        for(auto x : nums){
            sum+=x;
        }
        int n = nums.size();
        if(n==1 || n==2) return true;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,sum,m,nums,dp);
    }
};