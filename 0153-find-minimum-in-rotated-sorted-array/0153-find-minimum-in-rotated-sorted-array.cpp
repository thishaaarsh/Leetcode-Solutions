class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        if(nums[lo]<=nums[hi]){
            return nums[lo];
        }
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if( mid != 0 and nums[mid] < nums[mid-1]){
                return nums[mid];
            }
            if(nums[hi] < nums[mid]){
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return -1;
    }
};