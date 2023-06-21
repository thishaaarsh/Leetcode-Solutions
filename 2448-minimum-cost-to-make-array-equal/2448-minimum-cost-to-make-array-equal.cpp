class Solution {
public:
    long long solve(vector<int>& nums, vector<int>& cost, long long tar){
        long long sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += abs(1ll*tar-nums[i])*(1ll*cost[i]);
        }
        return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long s = *min_element(nums.begin(),nums.end());
        long long e = *max_element(nums.begin(),nums.end());
        while(s<e){
            long long mid = (s+e)/2;
            long long left = solve(nums,cost,mid);
            long long right = solve(nums,cost,mid+1);
            if(right > left){
                e = mid;
            }
            else{
                s = mid+1;
            }
        }
        return solve(nums,cost,s);
    }
};