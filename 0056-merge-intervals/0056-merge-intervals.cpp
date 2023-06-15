class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>>ans;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0; i<n; i++){
            int start = arr[i][0];
            int end = arr[i][1];
            if(!ans.empty() and ans.back()[1] >= end){
                continue;
            }
            for(int j=i+1; j<n; j++){
                if(arr[j][0] <= end){
                    end = max(end,arr[j][1]);
                }
                else break;
            }
            vector<int>temp = {start,end};
            ans.push_back(temp);
        }
        return ans;
    }
};