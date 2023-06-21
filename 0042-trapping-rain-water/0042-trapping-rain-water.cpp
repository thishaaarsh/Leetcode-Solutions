class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n-1;
        int lefth = 0, righth= 0;
        int ans = 0;
        while(left<=right){
            if(arr[left] <= arr[right]){
                if(arr[left] >= lefth){
                    lefth = arr[left];
                }
                else{
                    ans+=(lefth-arr[left]);
                }
                left++;
            }
            else{
                if(arr[right] >= righth){
                    righth = arr[right];
                }
                else{
                    ans+=(righth-arr[right]);
                }
                right--;
            }
        }
        return ans;
    }
};