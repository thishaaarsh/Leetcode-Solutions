class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char>stk;
        for(int i=0; i<n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()) return false;
                char a = stk.top();
                stk.pop();
                if((a=='(' and s[i] == ')') || (a=='{' and s[i]=='}') || (a=='[' and s[i] == ']')){
                    continue;
                }
                else return false;
            }
        }
        return stk.empty() == true;
    }
};