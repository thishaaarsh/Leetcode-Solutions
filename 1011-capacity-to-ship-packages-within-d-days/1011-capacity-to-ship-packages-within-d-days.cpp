class Solution {
public:
    bool solve(int mid, vector<int> &arr, int days){
        int temp = 0;
        int k = 1;
        for(int i=0; i<arr.size();i++){
            if(temp+arr[i] <= mid){
                temp+=arr[i];
            }
            else{
                k++;
                temp = arr[i];
            }
        }
        
        return k<=days;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        long long sum = 0;
        for(int x : arr){
            sum+=x;
        }
        int l = *max_element(arr.begin(),arr.end());
        int h = sum;
        int ans = 0;
        while(l<=h){
            int mid = (l+h)/2;
            if(solve(mid,arr,days)){
                ans = mid;
                h =mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
};