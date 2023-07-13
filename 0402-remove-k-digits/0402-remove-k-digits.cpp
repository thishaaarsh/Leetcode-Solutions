class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n==0 || k>=n) return "0";
        stack<char>s;
        for(int i=0; i<n; i++){
            while(s.empty() == false and s.top() > num[i] and k>0){
                s.pop();
                k--;
            }
            s.push(num[i]);
            if(s.size() == 1 and s.top() == '0'){
                s.pop();
            }
        }
        while(k and s.empty() == false){
            s.pop();
            k--;
        }
        if(s.empty()) return "0";
        else{
            string ans = "";
            while(s.empty() == false){
                ans+=s.top();
                s.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    }
};