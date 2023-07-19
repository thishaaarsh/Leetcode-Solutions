class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(s[i] == ' ')i++;
        long long ans = 0;
        bool neg = false;
        if(s[i]=='-'){
            neg = true;
            i++;
        }
        else if(s[i] == '+'){
            //neg = true;
            i++;
        }
        while(i<s.size()){
            if(s[i] >= '0' and s[i] <='9')
                ans = ans*10+(s[i]-'0');
            else break;
            if(ans > INT_MAX and neg) return INT_MIN;
            if(ans > INT_MAX) return INT_MAX;
            i++;
        }
        if(neg) return -1*ans;
        return ans;
        
        
    }
};