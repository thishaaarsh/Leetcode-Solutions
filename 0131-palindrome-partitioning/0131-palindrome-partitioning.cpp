class Solution {
public:
    bool isPal(int i, int j, string &s){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int i, int n,vector<string>&temp,vector<vector<string>>&ans,string &s ){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(int j=i; j<n; j++){
            if(isPal(i,j,s)){
                temp.push_back(s.substr(i,j-i+1));
                solve(j+1,n,temp,ans,s);
                temp.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        int i=0, n=s.size();
        solve(i,n,temp,ans,s);
        return ans;
    }
};