class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans1 = 0, ans2 = 0;
        int a = 1;
        for(int i=0; i<s.size();i++){
            if(a==1){
                if(s[i] != '1') ans1++;
            }
            else{
                if(s[i] != '0') ans1++;
            }
            if(a==1) a = 0;
            else a = 1;
        }
        a = 0;
        for(int i=0; i<s.size();i++){
            if(a==1){
                if(s[i] != '1') ans2++;
            }
            else{
                if(s[i] != '0') ans2++;
            }
            if(a==1) a = 0;
            else a = 1;
        }
        return min(ans1,ans2);
    }
};