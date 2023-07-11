class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[j] < arr[i]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};