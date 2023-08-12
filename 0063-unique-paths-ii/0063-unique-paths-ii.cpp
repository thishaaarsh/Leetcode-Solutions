class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& arr,vector<vector<int>>&dp ){
        if(i<0||j<0) return 0;
        if(arr[i][j] == 1) return 0;
        if(i==0 and j==0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] =  solve(i-1,j,arr,dp)+solve(i,j-1,arr,dp);
        
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
       // vector<vector<int>>dp(n,vector<int>(m,0));
        //return solve(n-1,m-1,arr,dp);
        vector<int>prev(m,0);
        if(arr[0][0] == 1) return 0;
        for(int i=0; i<n; i++){
            vector<int>temp(m,0);
            for(int j=0; j<m; j++){
                if(i==0 and j==0){
                    temp[j] = 1;
                    continue;
                }
                int a=0,b=0;
                if(i>0) a = prev[j];
                if(j>0) b = temp[j-1];
                if(arr[i][j] != 1){
                    temp[j] = a+b;
                }
            }
            prev = temp;
        }
        return prev[m-1];
    }
};