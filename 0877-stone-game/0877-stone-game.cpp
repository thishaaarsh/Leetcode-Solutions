class Solution {
public:
    int solve(int i, int j,vector<int>&arr,vector<vector<int>>&dp ){
    if(i>j) return 0;
    if(i==j) return arr[i];
    if(dp[i][j] != -1) return dp[i][j];
    int a = arr[i];
    int b = arr[j];
    if(i+1<arr.size() and arr[i+1] < arr[j]){
        a+=solve(i+1,j-1,arr,dp);
    }
    else{
        a+=solve(i+2,j,arr,dp);
    }
    if(j-1 >=0 and arr[j-1] > arr[i]){
        b+=solve(i,j-2,arr,dp);
    }
    else{
        b+=solve(i+1,j-1,arr,dp);
    }
    return dp[i][j] = max(a,b);
}
    bool stoneGame(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int a = solve(0,n-1,arr,dp);
        int sum =0 ;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        return a>(sum-a);

    }
};