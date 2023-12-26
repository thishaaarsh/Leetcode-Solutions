class Solution {
public:
    bool isSym(int num){
        string s = to_string(num);
        int n = s.size();
        if(n%2 != 0) return false;
        int sum1 = 0;
        for(int i=0; i<n/2; i++){
            sum1 = sum1+(s[i]-'0');
        }
        int sum2 = 0;
        for(int i=n/2; i<n; i++){
            sum2 = sum2+(s[i]-'0');
        }
        if(sum1==sum2) return true;
        return false;
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low; i<=high; i++){
            if(isSym(i) == true) count++;
        }
        return count;
    }
};