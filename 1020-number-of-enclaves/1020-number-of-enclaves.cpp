class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0; i<m; i++){
            if(!vis[0][i] and grid[0][i] == 1){
                q.push({0,i});
                vis[0][i] = 1;
            }
            if(!vis[n-1][i] and grid[n-1][i] == 1){
                q.push({n-1,i});
                vis[n-1][i] = 1;
            } 
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] and grid[i][0] == 1){
                q.push({i,0});
                vis[i][0] = 1;
            }
            if(!vis[i][m-1] and grid[i][m-1] == 1){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }
        int delrow[] = {0,0,1,-1};
        int delcol[] = {-1,1,0,0};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow >= 0  and ncol >=0 and nrow < n and ncol < m and
                  !vis[nrow][ncol] and grid[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(!vis[i][j] and grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};