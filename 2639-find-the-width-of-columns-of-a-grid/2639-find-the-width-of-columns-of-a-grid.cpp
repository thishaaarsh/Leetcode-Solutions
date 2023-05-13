class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<int>ans;
        for(int i=0; i<m; i++){
            int maxi = 0;
            for(int j=0; j<n; j++){
                string a = to_string(arr[j][i]);
                int  p = a.size();
                maxi = max(maxi,p);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};