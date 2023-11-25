class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int currsum = 0;
        int ans = INT_MIN;
        for(int i=0; i<arr.size();i++){
            currsum+=arr[i];
            ans = max(ans,currsum);
            if(currsum < 0){
                currsum = 0;
            }
        }
        return ans;
    }
};