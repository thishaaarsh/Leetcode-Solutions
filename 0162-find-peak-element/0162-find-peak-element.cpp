class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int lo = 0, hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if((mid==0 || arr[mid] >= arr[mid-1]) and (mid==n-1 || arr[mid] >= arr[mid+1])){
                return mid;
            }
            if(mid > 0 and arr[mid-1] >= arr[mid]){
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return -1;
    }
};