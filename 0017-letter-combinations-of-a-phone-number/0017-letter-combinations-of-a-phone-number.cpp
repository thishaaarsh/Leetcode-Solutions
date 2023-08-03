class Solution {
public:
    void solve(int i, int n, string &s, vector<string>&ans, string &arr,map<char,vector<char>>&mp){
        if(i==n){
            ans.push_back(s);
        }
        for(auto it:mp[arr[i]]){
            s.push_back(it);
            solve(i+1,n,s,ans,arr,mp);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string arr) {
        map<char,vector<char>>mp;
        mp['2'] = {'a','b','c'};
        mp['3'] = {'d','e','f'};
        mp['4'] = {'g','h','i'};
        mp['5'] = {'j','k','l'};
        mp['6'] = {'m','n','o'};
        mp['7'] = {'p','q','r','s'};
        mp['8'] = {'t','u','v'};
        mp['9'] = {'w','x','y','z'};
        vector<string>v;
        string s = "";
        int i=0, n=arr.size();
        if(n==0) return v;
        solve(i,n,s,v,arr,mp);
        return v;
    }
};