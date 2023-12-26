class Solution {
public:
   //  001100 => 000110 => 000011 => 000001 => 000000
    int solve(int num){
        int a = 0;
        while(num){
            if(num & 1 == 1) a++;
            num = num >> 1;
        }
        return a;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0; i<nums.size();i++){
            int a = solve(i);
            if(a==k) ans+=nums[i];
        }
        return ans;
    }
};