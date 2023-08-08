class Solution {
public:
    int search(vector<int>& arr, int x) {
        int n = arr.size();
        int lo = 0, hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid] == x) return mid;
            else if(arr[mid] >= arr[lo]){
                if(arr[lo] <= x and arr[mid] >= x){
                    hi = mid-1;
                }
                else lo = mid+1;
            }
            else{
                if(arr[hi] >= x and arr[mid] <= x){
                    lo = mid+1;
                }
                else hi = mid-1;
            }
        }
        return -1;
    }
};