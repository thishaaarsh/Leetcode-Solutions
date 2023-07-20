class Solution {
public:
    vector<int> solve(int i){
        vector<int>ans;
        ans.push_back(1);
        for(int j=1; j<i; j++){
            int res = ans.back()*(i-j);
            res = res/j;
            ans.push_back(res);
        }
        return ans;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i=1; i<=n; i++){
            vector<int>a = solve(i);
            ans.push_back(a);
        }
        return ans;
        
    }
};