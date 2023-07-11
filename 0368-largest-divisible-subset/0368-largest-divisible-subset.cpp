class Solution {
public:
    // int solve(int i, int j, int n, vector<int>&arr){
    //     if(i==n) return 0;
    //     int nottake = solve(i+1,j,n,arr);
    //     int take = INT_MIN;
    //     if(j==-1 || arr[i]%arr[j]==0){
    //         take = 1+solve(i+1,i,n,arr);
    //     }
    //     return max(take,nottake);
    // }
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
       // return solve(0,-1,n,arr);
        vector<int>dp(n,1),hash(n,0);
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(arr[i]%arr[j]==0 and dp[i]<dp[j]+1){
                    hash[i] = j;
                    dp[i] = dp[j]+1;
                }
            }
        }
        int maxi = 0;
        int lastidx = 0;
        for(int i=0; i<n; i++){
            if(dp[i]>maxi){
                maxi = dp[i];
                lastidx = i;
            }
        }
        vector<int>ans;
        ans.push_back(arr[lastidx]);
        while(hash[lastidx] != lastidx){
            lastidx = hash[lastidx];
            ans.push_back(arr[lastidx]);
        }
        return ans;
    }
};