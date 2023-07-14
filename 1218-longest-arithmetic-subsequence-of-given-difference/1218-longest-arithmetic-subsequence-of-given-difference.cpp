class Solution {
public:
    int longestSubsequence(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int ans  = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(mp.count(arr[i]-k)==0){
                mp[arr[i]] = 1;
            }
            else{
                mp[arr[i]] = 1+mp[arr[i]-k];
            }
            ans = max(ans,mp[arr[i]]);
        }
        return ans;
    }
};