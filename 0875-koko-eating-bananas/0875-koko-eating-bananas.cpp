class Solution {
public:
    bool ispossible(int mid, vector<int>& arr, int h){
        long long time = 0;
        for(int i=0; i<arr.size();i++){
            time+=ceil(arr[i]/(double)mid);
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int lo = 1;
        int hi = *(max_element(arr.begin(),arr.end()));
        int ans = 0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(ispossible(mid,arr,h)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};