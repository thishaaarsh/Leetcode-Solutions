class Solution {
public:
    int maxCoins(vector<int>& arr) {
        int n = arr.size();
        n = n/3;
        int ans = 0;
        sort(arr.begin(),arr.end());
        for(int i=0; i<n; i++){
            ans+=(arr[arr.size()-(i+1)*2]);
        }
        return ans;
    }
};