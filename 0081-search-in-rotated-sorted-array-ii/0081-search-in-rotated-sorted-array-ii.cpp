class Solution {
public:
    bool search(vector<int>& arr, int tar) {
        int lo = 0, hi = arr.size()-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid] == tar) return true;
            if(arr[lo] == arr[mid] and arr[mid] == arr[hi]){
                lo++;
                hi--;
                continue;
            }
            if(arr[lo] <= arr[mid]){
                if(arr[lo] <= tar and arr[mid] >= tar){
                    hi = mid-1;
                }
                else lo = mid+1;
            }
            else{
                if(arr[hi] >= tar and arr[mid] <= tar){
                    lo = mid+1;
                }
                else hi = mid-1;
            }
        }
        return false;
    }
};