class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int a = 1;
        int zero = 0;
        for(int i=0; i<nums.size();i++){
            if(nums[i] != 0){
                a = a*nums[i];
            }
            else{
                zero++;
            }
        }
        if(zero > 1){
            return ans;
        }
        else{
            for(int i=0; i<nums.size();i++){
                if(zero == 1){
                    if(nums[i] == 0){
                        ans[i] = a;
                    }
                    else{
                        ans[i] = 0;
                    }
                }
                else{
                    ans[i] = a/nums[i];
                }
            }
        }
        return ans;
    }
};