class Solution {
public:
    string removeKdigits(string num, int k) {
    int n = num.size();
        if(n==0) return "0";
        if(k>=n) return "0";
        stack<char>s;
        for(int i=0; i<n; i++){
            while(s.empty() == false and k>0 and s.top()>num[i]){
                s.pop();
                k--;
            }
            s.push(num[i]);
            if(s.size() == 1 and num[i] == '0') s.pop();
        }
        while(s.empty() == false and k>0){
            s.pop();
            k--;
        }
        if(s.empty()) return "0";
        string ans = "";
        while(s.empty() == false){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};