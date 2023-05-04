class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int>s;
        int n = arr.size();
        for(int i=0; i<n; i++){
            s.insert(arr[i]);
        }
        int ans =0;
        for(auto num : arr){
            if(!s.count(num-1)){
                int curr = num;
                int steak = 1;
                while(s.count(curr+1)){
                    curr++;
                    steak++;
                }
                ans = max(ans,steak);
            }
            
        }
        return ans;
    }
};