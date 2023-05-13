class Solution {
public:
    bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int ans = 0;
        int i=0, j=0;
        while(i<n and j<m){
            if(isPrime(nums[i][j])){
                ans = max(ans,nums[i][j]);
            }
            i++;
            j++;
        }
        i = 0;
        j = m-1;
        while(i<n and j>=0){
            if(isPrime(nums[i][j])){
                ans = max(ans,nums[i][j]);
            }
            i++;
            j--;
        }
        return ans;
    }
};