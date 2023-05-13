class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int>ans;
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<k-1; i++){
            mp[nums[i]]++;
        }
        int ct = 0;
        for(int i=k-1; i<n;i++){
            mp[nums[i]]++;
            int a = 0;
            int c = 0;
            for(int j=-50; j<0; j++){
                a+=mp[j];
                if(a>=x){
                    c = j;
                    break;
                }
            }
            ans.push_back(c);
            mp[nums[ct]]--;
            ct++;
        }
        return ans;
    }
};