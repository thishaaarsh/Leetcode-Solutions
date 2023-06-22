class Solution {
public:
    bool solve(int mid, vector<int>&arr, int k){
        int sum = 0;
        for(int i=0; i<arr.size();i++){
            sum+=ceil(arr[i]/(double)mid);
        }
        return sum<=k;
    }
    int smallestDivisor(vector<int>& nums, int k) {
        //int n = arr.size();
        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while(l<=h){
            int mid = (l+h)/2;
            if(solve(mid,nums,k)){
                ans = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};