class Solution {
public:
    int vis[1001];
    int solve(vector<int>& nums, int k, int i){
        if(i==nums.size()) return 1;
        int take = 0;
        if(nums[i]-k < 0 || vis[nums[i]-k] == 0){
            vis[nums[i]]++;
            take = solve(nums,k,i+1);
            vis[nums[i]]--;
        }
        int nottake = solve(nums,k,i+1);
        return take+nottake;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        memset(vis,0,sizeof(vis));
        return solve(nums,k,0)-1;
    }
};