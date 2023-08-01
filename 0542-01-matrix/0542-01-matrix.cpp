class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        queue<pair<int,pair<int,int>>>q;
        // dis row col
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == 0){
                    q.push({0,{i,j}});
                }
            }
        }
        vector<vector<int>>ans(n,vector<int>(m,0));
        int delrow[] = {0,0,1,-1};
        int delcol[] = {1,-1,0,0};
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow >=0 and ncol >= 0 and nrow<n and ncol < m and arr[nrow][ncol]){
                    arr[nrow][ncol] = 0;
                    ans[nrow][ncol] = dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        return ans;
    }
};