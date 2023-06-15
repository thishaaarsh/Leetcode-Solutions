class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            if(i==0 || nums[i] != nums[i-1]){
                for(int j=i+1; j<n; j++){
                    if(j==i+1 || nums[j] != nums[j-1]){
                        int lo = j+1;
                        int hi = n-1;
                        while(lo<hi){
                            long long sum = (long long)nums[i]+(long long)nums[j]+
                                (long long)nums[lo]+ (long long)nums[hi];
                            if(sum == target){
                                vector<int>temp = {nums[i], nums[j], nums[lo], nums[hi]};
                                ans.push_back(temp);
                                while(lo<hi and nums[lo] == nums[lo+1]) lo++;
                                while(lo<hi and nums[hi] == nums[hi-1]) hi--;
                                lo++;
                                hi--;
                            }
                            else if(sum < target) lo++;
                            else hi--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};