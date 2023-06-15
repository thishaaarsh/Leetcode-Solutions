class Solution {
public:
    int first(vector<int>& nums, int x){
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if((mid == 0 || x>nums[mid-1]) and nums[mid] == x){
                return mid;
            }
            else if(nums[mid] < x){
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return -1;
    }
    
    int last(vector<int>& nums, int x){
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if((mid == n-1 || x < nums[mid+1]) and nums[mid] == x){
                return mid;
            }
            else if(nums[mid] > x){
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = first(nums,target);
        int b = last(nums,target);
        vector<int> ans = {a,b};
        return ans;
    }
};