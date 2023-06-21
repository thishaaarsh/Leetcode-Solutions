class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k >= n) return "0";
        if(n==0) return "0";
        if(k==0) return num;
        stack<char>s;
        s.push(num[0]);
        for(int i=1; i<n; i++){
            while(!s.empty() and k >0 and s.top() > num[i]){
                s.pop();
                k--;
            }
            s.push(num[i]);
            if(s.size() == 1 and num[i] == '0')
                s.pop();
            
        }
        while(k>0 and s.empty() == false){
            k--;
            s.pop();
        }
        string ans = "";
        while(s.empty() == false){
            ans.push_back(s.top());
            s.pop();
        }
        if(ans.size() == 0) return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    
        
    }
};