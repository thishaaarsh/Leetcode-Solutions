class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        int lo = 0, hi = n-1;
        int lmax = 0, hmax = 0;
        while(lo<hi){
            if(arr[lo] <= arr[hi]){
                if(arr[lo] >= lmax) lmax = arr[lo];
                else res+=(lmax-arr[lo]);
                lo++;
            }
            else{
                if(arr[hi] >= hmax) hmax = arr[hi];
                else res+=(hmax-arr[hi]);
                hi--;
            }
        }
        return res;
    }
};