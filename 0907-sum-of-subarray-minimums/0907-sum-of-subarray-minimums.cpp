class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int>s;
        int mod = 1e9+7;
        vector<int>pse(n,-1),nse(n,n);
        for(int i=0; i<n; i++){
            while(s.empty() == false and arr[s.top()] > arr[i]){
                s.pop();
            }
            if(!s.empty()){
                pse[i] = s.top();
            }
            s.push(i);
        }
         while(!s.empty()){
            s.pop();
        }
        for(int i=n-1; i>=0; i--){
            while(s.empty() == false and arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(!s.empty()){
                nse[i] = s.top();
            }
            s.push(i);
        }
       
        long long ans = 0;
        for(int i=0; i<n; i++){
            int left = i-pse[i];
            int right = nse[i]-i;
            ans = (ans+1ll*left*right*arr[i]) % mod;
        }
        return ans;
    }
};