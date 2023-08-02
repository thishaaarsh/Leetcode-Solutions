class Solution {
public:
    void solve(int i, int n, vector<int>& nums, vector<vector<int>>&ans, vector<int>&v){
        if(i==n){
            ans.push_back(nums);
        }
        for(int j=i; j<n; j++){
            swap(nums[i],nums[j]);
            solve(i+1,n,nums,ans,v);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(0,nums.size(),nums,ans,v);
        return ans;
    }
};