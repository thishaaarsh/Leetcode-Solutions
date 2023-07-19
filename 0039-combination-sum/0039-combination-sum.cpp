class Solution {
public:
    void solve(int i, int n, vector<int>&temp,vector<vector<int>>&ans,int k,vector<int>& arr){
        if(k==0 and i==n){
            ans.push_back(temp);
        }
        if(i==n){
            return;
        }
        if(arr[i] <= k){
            temp.push_back(arr[i]);
            solve(i,n,temp,ans,k-arr[i],arr);
            temp.pop_back();
        }
        solve(i+1,n,temp,ans,k,arr);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<vector<int>>ans;
        int n = arr.size();
        if(n==0) return ans;
        vector<int>temp;
        solve(0,n,temp,ans,k,arr);
        return ans;
    }
};