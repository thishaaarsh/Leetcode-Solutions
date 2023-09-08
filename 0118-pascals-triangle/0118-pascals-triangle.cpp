class Solution {
public:
    vector<int>solve(int n){
        vector<int>res;
        res.push_back(1);
        int ans = 1;
        for(int i=1; i<n; i++){
            ans*=(n-i);
            ans/=i;
            res.push_back(ans);
        }
        return res;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i=1; i<=n; i++){
            ans.push_back(solve(i));
        }
        return ans;
    }
};