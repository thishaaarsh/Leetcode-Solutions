class Solution {
public:
    int mod = 1e9+7;
    long long solve(long long x, long long pow){
        if(pow == 0) return 1;
       // if(pow == 1) return x;
        long long int res = solve(x,pow/2);
        res = (res*res)%mod;
        if(pow%2==1) res = (x*res)%mod;
        return res;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n-odd;
        return (solve(5,even)%mod*(solve(4,odd)%mod))%mod;
    }
};