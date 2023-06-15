class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        int mid;
        if(hi == 0) return nums[0];
        else if(nums[0] != nums[1]) return nums[0];
        else if(nums[n-1] != nums[n-2]) return nums[n-1];
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1])
                return nums[mid];
            else if((mid%2==0 and nums[mid] == nums[mid+1]) || (mid%2 and nums[mid] == nums[mid-1])){
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return -1;
    }
};