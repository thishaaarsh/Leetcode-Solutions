class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int ans = 0;
        unordered_map<int,int>mp;
        int sum = 0;
        for(int i=0; i<arr.size();i++){
            sum+=arr[i];
            ans+=mp[sum-k];
            if(sum == k) ans++;
            mp[sum]++;
        }
        return ans;
    }
};