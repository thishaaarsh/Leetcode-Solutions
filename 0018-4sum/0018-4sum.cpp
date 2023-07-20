class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0; i<n; i++){
            if(i==0 || arr[i] != arr[i-1]){
                for(int j=i+1; j<n; j++){
                    if(j==i+1 || arr[j] != arr[j-1]){
                        int lo = j+1, hi = n-1;
                       // long long sum = 
                        while(lo<hi){
                            long long sum = 1ll*arr[lo]+ 1ll*arr[hi]+1ll*arr[i]+1ll*arr[j];;
                            if(sum==target){
                                vector<int>temp = {arr[i],arr[j],arr[lo],arr[hi]};
                                ans.push_back(temp);
                                while(lo<hi and arr[lo]==arr[lo+1]) lo++;
                                while(lo<hi and arr[hi] == arr[hi-1]) hi--;
                                lo++;
                                hi--;
                            }
                            else if(sum>target){
                                hi--;
                            }
                            else lo++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};