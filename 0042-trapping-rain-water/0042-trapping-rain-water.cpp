class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int>lmax(n),rmax(n);
        lmax[0] = arr[0];
        for(int i=1; i<n; i++){
            lmax[i] = max(arr[i],lmax[i-1]);
        }
        rmax[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            rmax[i] = max(arr[i],rmax[i+1]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans+=min(rmax[i],lmax[i])-arr[i];
        }
        return ans;
        
    }
};