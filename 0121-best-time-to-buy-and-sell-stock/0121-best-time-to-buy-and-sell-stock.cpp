class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int mini = arr[0];
        for(int i=1; i<n; i++){
            ans = max(ans,arr[i]-mini);
            mini = min(mini,arr[i]);
        }
        return ans;
    }
};