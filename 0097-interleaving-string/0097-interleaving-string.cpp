class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())return false;
        vector<vector<bool>>dp(s1.length()+1,vector<bool>(s2.length()+1));
        dp[0][0]=1; //satisfies because s1,s2,and s3 are empty strings
        for(int j=1;j<s2.length()+1;j++){ //check when s1 length is zero
             dp[0][j]=dp[0][j-1]&&(s2[j-1]==s3[j-1]);
        }
        for(int i=1;i<s1.length()+1;i++){ //check when s2 length is zero
             dp[i][0]=dp[i-1][0]&&(s1[i-1]==s3[i-1]);
        }
        for(int i=1;i<s1.length()+1;i++){
            for(int j=1;j<s2.length()+1;j++){
                bool a=(s1[i-1]==s3[i+j-1])&&dp[i-1][j];
                bool b=(s2[j-1]==s3[i+j-1])&&dp[i][j-1];
                dp[i][j]=a||b;
            }
        }
        return dp[s1.length()][s2.length()];
    }
};