class Solution {
public:
    int maximumBeauty(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        //int ans = 0;
        int lo = 0, hi = 0;
        int ans = 0;
        while(hi<arr.size()){
            if(arr[hi]-arr[lo] <= 2*k){
                ans = max(ans, hi-lo+1);
                hi++;
            }
            else lo++;
        }
        return ans;
        
    }
};