class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int m = arr[0].size();
        if(n==0) return false;
        int lo = 0, hi=m*n-1;
        while(lo<=hi){
            int mid = (lo+hi)>>1;
            int row = mid/m;
            int col = mid%m;
            if(arr[row][col] == k){
                return true;
            }
            else if(arr[row][col] > k)
                hi = mid-1;
            else lo = mid+1;
            
        }
        return false;
    }
};