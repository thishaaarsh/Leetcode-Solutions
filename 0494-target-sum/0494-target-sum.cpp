class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int k) {
        if(k<0) k = -k;
        int sum = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        int t = sum-k;
        if(t<0) return 0;
        if(t%2) return 0;
        t = t/2;
        vector<vector<int>>dp(n+1,vector<int>(t+1,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<=t;j++){
                if(i==0 and j==0  and arr[0] == 0){
                    dp[0][0] = 2;
                    continue;
                }
                if(j==0){
                    dp[i][j] = 1;
                }
                if(i==0){
                    if(arr[i] == j){
                        dp[i][j] = 1;
                    }
                }
                else{
                    int nottake = dp[i-1][j];
                    int take = 0;
                    if(j>=arr[i]){
                        take = dp[i-1][j-arr[i]];
                    }
                    dp[i][j] = take+nottake;
                }
            }
        }
        return dp[n-1][t];
    }
};