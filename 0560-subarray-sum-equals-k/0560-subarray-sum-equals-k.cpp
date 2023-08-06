class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum==k) ans++;
            int req = sum-k;
            ans+=mp[req];
            mp[sum]++;
        }
        return ans;
    }
};