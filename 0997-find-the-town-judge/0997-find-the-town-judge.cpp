class Solution {
public:
    int findJudge(int n, vector<vector<int>>& arr) {
        if(n==1) return 1;
        if(arr.size() == 0) return -1;
        unordered_map<int,int>mp;
        for(int i=0; i<arr.size();i++){
            mp[arr[i][1]]++;
        }
        vector<int>a;
        for(auto x:mp){
            if(x.second==n-1)
                a.push_back(x.first);
        }
        int ans = -1;
        for(int i=0; i<a.size();i++){
            bool flag = true;
            for(int j=0; j<arr.size();j++){
                if(arr[j][0] == a[i]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return a[i];
        }
        return ans;
        
    }
};