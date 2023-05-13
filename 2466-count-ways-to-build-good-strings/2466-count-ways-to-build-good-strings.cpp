class Solution {
public:
    int arr[100001];
    int solve(int i, int zero, int one){
        if(i==0)
            return 1;
        if(i < 0)
            return 0;
        if(arr[i] != -1) return arr[i];
        return arr[i] = (solve(i-zero,zero,one) %1000000007 +solve(i-one,zero,one)%1000000007)%1000000007;
        
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        memset(arr,-1,sizeof(arr));
        for(int i=low; i<=high; i++){
            
            ans = (ans + solve(i,zero,one)) % 1000000007;
        }
        return ans;
    }
};