class Solution {
public:
    int pivotInteger(int n) {
        int right = 0;
        for(int i=1; i<=n; i++){
            right+=i;
        }
        int left = 0;
        for(int i=1; i<=n; i++){
            left+=i;
            if(left==right) return i;
            right-=i;
        }
        return -1;
    }
};