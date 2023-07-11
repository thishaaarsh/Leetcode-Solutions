class Solution {
public:
    void solve(int i, int j, int n, string s, vector<string>&ans){
        if(j>i || i>n || j>n) return;
        if(i==n and j==n){
            ans.push_back(s);
        }
        s.push_back('(');
        solve(i+1,j,n,s,ans);
        s.pop_back();
        s.push_back(')');
        solve(i,j+1,n,s,ans);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s = "";
        solve(0,0,n,s,ans);
        return ans;
    }
};