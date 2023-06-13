class Solution {
public:
    int equalPairs(vector<vector<int>>& arr) {
        map<vector<int>,int>mp;;
        for(int i=0; i<arr.size();i++){
            vector<int>temp;
            for(int j=0; j<arr.size();j++){
                temp.push_back(arr[i][j]);
            }
            mp[temp]++;
        }
        int ans = 0;
        for(int i=0; i<arr.size();i++){
            vector<int>temp;
            for(int j=0; j<arr.size();j++){
                temp.push_back(arr[j][i]);
            }
            if(mp.find(temp) != mp.end())
                ans += mp[temp];
        }
        return ans;
    }
};