class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = k*nums[nums.size()-1]+((k)*(k-1))/2;
        return ans;
    }
};