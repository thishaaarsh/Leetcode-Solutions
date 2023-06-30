class Solution {
public:
    vector<int> solve(int n){
        vector<int>temp;
        int res = 1;
        temp.push_back(res);
        for(int i=1; i<n; i++){
            res = res*(n-i);
            res = res/i;
            temp.push_back(res);
        }
        return temp;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i=1; i<=n; i++){
            vector<int>temp = solve(i);
            ans.push_back(temp);
        }
        return ans;
    }
};