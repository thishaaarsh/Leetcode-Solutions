class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0; i<n; i++){
            if(i==0 || nums[i] != nums[i-1]){
                int lo = i+1;
                int hi = n-1;
                while(lo<hi){
                    if(nums[i]+nums[lo]+nums[hi] == 0){
                        vector<int>temp({nums[i],nums[lo],nums[hi]});
                    
                        ans.push_back(temp);
                        while(lo<hi and nums[lo]==nums[lo+1]) lo++;
                        while(lo<hi and nums[hi] == nums[hi-1]) hi--;
                        lo++;
                        hi--;
                    }
                    else if(nums[i]+nums[lo]+nums[hi] > 0) hi--;
                    else lo++;
                }
            }
        }
        return ans;
        
    }
};