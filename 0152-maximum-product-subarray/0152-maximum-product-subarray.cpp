class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maxi = arr[0];
        int mini = arr[0];
        int ans = arr[0];
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i] < 0){
                swap(maxi,mini);
            }
            maxi = max(arr[i],arr[i]*maxi);
            mini = min(arr[i],arr[i]*mini);
            ans = max(ans,maxi);
        }
        return ans;
    }
};