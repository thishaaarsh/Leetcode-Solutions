class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<int>row;
        vector<int>col;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++){
                if(arr[i][j] == 1)
                    count++;
            }
            row.push_back(count);
        }
        
        for(int i=0; i<m; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(arr[j][i] == 1)
                    count++;
            }
            col.push_back(count);
        }
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j=0; j<m; j++){
                temp.push_back(row[i]+col[j]-n+row[i]-m+col[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};