class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int ans = nums[0];
        for(int i=0; i<n; i++){
            if(nums[i] == ans){
                count++;
            }
            else{
                count--;
            }
            if(count == 0){
                ans = nums[i];
                count = 1;
            }
        }
        return ans;
    }
};