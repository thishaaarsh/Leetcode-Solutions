class Solution {
public:
    string replaceDigits(string s) {
        int n = s.size();
        for(int i=1; i<n; i=i+2){
            char p = s[i-1]+(s[i]-'0');
            s[i] = p;
        }
        return s;
    }
};