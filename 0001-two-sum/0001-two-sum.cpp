class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0; i<arr.size(); i++){
            if(mp.find(target-arr[i]) != mp.end()){
                //vector<int>ans;
                ans.push_back(mp[target-arr[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[arr[i]] = i;
        }
        return ans;
        
    }
};