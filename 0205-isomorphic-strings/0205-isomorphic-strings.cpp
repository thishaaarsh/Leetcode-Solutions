class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp,mpp;
        if(s.size() != t.size()) return false;
        for(int i=0; i<s.size();i++){
            mp[s[i]] = t[i];
            //mp[t[i]] = s[i];
        }
        for(int i=0; i<t.size();i++){
            mpp[t[i]] = s[i];
        }
        string tt = "";
        for(int i=0; i<s.size();i++){
            tt.push_back(mp[s[i]]);
        }
        string ss = "";
        for(int i=0; i<t.size();i++){
            ss.push_back(mpp[t[i]]);
        }
        return (ss == s and tt == t);
    }
};