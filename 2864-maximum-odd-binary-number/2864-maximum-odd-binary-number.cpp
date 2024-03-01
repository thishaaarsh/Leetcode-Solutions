class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int c = -1;
        for(int i=0; i<n; i++){
            if(s[i] == '1') c++;
        }
        s[n-1] = '1';
        for(int i=0; i<n-1; i++){
            if(c>0){
                s[i] = '1';
                c--;
            }
            else{
                s[i] = '0';
            }
        }
        return s;
    }
};