class Solution {
public:
    // int solve(string &s, unordered_map<char,int>&mp, int i ){
    //     if(i==s.size()) return 0;
    //     int a = mp[s[i]]+solve(s,mp,i+1);
    //     int b = solve(s,mp,i+1);
    //     return max(a,b);
    // }
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int>mp;
        mp[' '] = 0;
        for(char i = 'a'; i<='z';i++){
            mp[i] = i-'a'+1;
        }
        for(int i=0; i<chars.size();i++){
            mp[chars[i]] = vals[i];
        }
        //return solve(s,mp,0);
        vector<int>temp;
        for(int i=0; i<s.size();i++){
            temp.push_back(mp[s[i]]);
        }
        int ans = 0;
        int t = 0;
        for(int i=0; i<s.size(); i++){
            t+=temp[i];
            if(t<0){
                t= 0;
            }
            ans = max(ans,t);
        }
        return ans;
        
    }
};