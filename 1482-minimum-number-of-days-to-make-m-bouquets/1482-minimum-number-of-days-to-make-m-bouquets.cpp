class Solution {
public:
    bool solve(int mid, vector<int>&arr, int m, int k){
        vector<int>temp(arr.size(),0);
        for(int i=0; i<arr.size();i++){
            if(arr[i] <= mid)
                temp[i]++;
        }
        int i=0;
        int buk = k;
        while(i<arr.size()){
            if(temp[i] == 1){
                k--;
                if(k==0){
                    k = buk;
                    m--;
                }
                if(m==0) return true;
            }
            else{
                k = buk;
            }
            i++;
        }
        return false;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        int l = arr[0];
        int h = arr[0];
        for(int i=0; i<n; i++){
            l = min(l,arr[i]);
            h = max(h,arr[i]);
        }
        int ans = -1;
        while(l<=h){
            int mid = (l+h)/2;
            if(solve(mid,arr,m,k)){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};