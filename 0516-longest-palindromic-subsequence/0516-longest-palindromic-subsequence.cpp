class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(),s1.end());
        int n = s1.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(i==0){
                    dp[i][j] = 0;
                }
                else if(j==0){
                    dp[i][j] = 0;
                }
                else{
                    if(s[i-1]==s1[j-1]){
                        dp[i][j] = 1+dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }
        return dp[n][n];
    }
};